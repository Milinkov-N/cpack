#include "cpack.h"

cmd_t cli_get_cmd(int argc, char **argv) {
  cmd_t command = CmdUnknown;

  if (argc < 1 || argv == NULL) return CmdUnknown;

  if (!strcmp(argv[1], "new")) {
    command = CmdNew;
  } else if (!strcmp(argv[1], "init")) {
    command = CmdInit;
  }

  return command;
}

void cli_parse_flags(flags_t *flags, int argc, char **argv) {
  if (flags == NULL || argc < 1 || argv == NULL) return;

  for (int i = 0; i < argc && argv[i] != NULL; i++) {
    if (!strcmp(argv[i], "--lib")) {
      if (flags->proj_type[0] == 0) strncpy(flags->proj_type, argv[i] + 2, 15);
    } else if (!strcmp(argv[i], "--bin")) {
      if (flags->proj_type[0] == 0) strncpy(flags->proj_type, argv[i] + 2, 15);
    } else if (!strncmp(argv[i], "-t", 2)) {
      if (flags->proj_type[0] == 0) strncpy(flags->proj_type, argv[i] + 2, 15);
    } else if (!strcmp(argv[i], "--git")) {
      flags->git = ENABLED;
    }
  }

  if (flags->proj_type[0] == 0) sprintf(flags->proj_type, "bin");
}
