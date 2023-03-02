#ifndef CPACK_INCLUDE_CLI_H_
#define CPACK_INCLUDE_CLI_H_

#include "cpack/error.h"

typedef enum command {
  CmdNew,
  CmdInit,
  CmdUnknown,
} cmd_t;

typedef enum flag {
  FlagBin,
  FlagLib,
  FlagTemplate,
  FlagGit,
  FlagUnknown = -1,
} flag_t;

typedef struct flags {
  char proj_type[16];
  char git;
} flags_t;

cmd_t cli_get_cmd(int argc, char **argv);

result_t cli_parse_flags(flags_t *flags, int argc, char **argv);

void handle_parse_error(result_t err, cmd_t cmd);

#endif  // CPACK_INCLUDE_CLI_H_