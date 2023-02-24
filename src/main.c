#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "cpack.h"

int main(int argc, char *argv[]) {
  if (argc < 3) printf("Usage: %s <project name> <dir name>\n", argv[0]);

  switch (cpack_create_project(argv[1], argv[2])) {
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

  return 0;
}
