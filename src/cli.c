#include "cpack.h"

static flag_t __what_flag(const char *flag);

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

result_t cli_parse_flags(flags_t *flags, int argc, char **argv) {
  result_t res = OK;
  if (flags == NULL || argc < 1 || argv == NULL) return ERR;

  for (int i = 0; i < argc && argv[i] != NULL && res == OK; i++) {
    if (*argv[i] == '-') {
      switch (__what_flag(argv[i])) {
        case FlagLib:
          if (!strlen(flags->proj_type))
            strncpy(flags->proj_type, argv[i] + 2, 15);
          else
            res = ERR_MULTIPLE_TEMPLATES;
          break;
        case FlagBin:
          if (!strlen(flags->proj_type))
            strncpy(flags->proj_type, argv[i] + 2, 15);
          else
            res = ERR_MULTIPLE_TEMPLATES;
          break;
        case FlagTemplate:
          if (!strlen(flags->proj_type))
            strncpy(flags->proj_type, argv[i] + 2, 15);
          else
            res = ERR_MULTIPLE_TEMPLATES;
          break;
        case FlagGit:
          flags->git = ENABLED;
          break;
        case FlagUnknown:
          res = ERR_UNKNOWN_FLAG;
          break;
      }
    }
  }

  if (!strlen(flags->proj_type)) sprintf(flags->proj_type, "bin");
  return res;
}

void handle_parse_error(result_t err, cmd_t cmd) {
  switch (err) {
    case ERR:
      fprintf(stderr, "Error: No arguments was given\n");
      break;

    case ERR_MULTIPLE_TEMPLATES:
      fprintf(stderr, "Error: Multiple templates was given.\n%s",
              cmd == CmdNew ? HELP_USAGE_NEW : HELP_USAGE_INIT);
      break;

    case ERR_UNKNOWN_FLAG:
      fprintf(stderr, "Error: Unknown flag was given.\n%s",
              cmd == CmdNew ? HELP_USAGE_NEW : HELP_USAGE_INIT);
      break;

    default:
      fprintf(stderr, ERRMSG_UNEXPECTED);
      break;
  }
}

static flag_t __what_flag(const char *flag) {
  int out = FlagUnknown;
  if (!strcmp(flag, "--lib")) {
    out = FlagLib;
  } else if (!strcmp(flag, "--bin")) {
    out = FlagBin;
  } else if (!strncmp(flag, "-t", 2)) {
    out = FlagTemplate;
  } else if (!strcmp(flag, "--git")) {
    out = FlagGit;
  }

  return out;
}
