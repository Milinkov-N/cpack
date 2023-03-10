#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "cpack.h"

int main(int argc, char *argv[]) {
  flags_t flags = {0};

  switch (cli_get_cmd(argc, argv)) {
    case CmdNew: {
      result_t parse_res = cli_parse_flags(&flags, argc, argv);

      if (parse_res == OK)
        cpack_create_project(argv[2], flags.proj_type);
      else
        handle_parse_error(parse_res, CmdNew);
      break;
    }
    case CmdInit: {
      result_t parse_res = cli_parse_flags(&flags, argc, argv);

      if (parse_res == OK) {
        switch (cpack_create_project(".", flags.proj_type)) {
          case OK:
            printf("Successfully created new porject\n");
            break;
          case ERR_CR_PROJ_FOLDER:
            fprintf(stderr, "Error: Failed to create project folder\n");
            break;
          case ERR_TEMP_NOT_FOUND:
            fprintf(stderr, "Error: Unknown project template `%s`\n", argv[2]);
            break;
          default:
            fprintf(stderr, ERRMSG_UNEXPECTED);
            break;
        }

        printf("project type: %s\n", flags.proj_type);
        printf("with git: %s\n", flags.git == ENABLED ? "true" : "false");
      } else {
        handle_parse_error(parse_res, CmdInit);
      }
      break;
    }

    case CmdUnknown:
      fprintf(stderr, "Error: Unknown command `%s`\n", argv[1]);
      break;
  }

  return 0;
}
