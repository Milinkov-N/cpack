#ifndef CPACK_INCLUDE_CLI_H_
#define CPACK_INCLUDE_CLI_H_

typedef enum command {
  CmdNew,
  CmdInit,
  CmdUnknown,
} cmd_t;

typedef struct flags {
  char proj_type[16];
  char git;
} flags_t;

cmd_t cli_get_cmd(int argc, char **argv);

void cli_parse_flags(flags_t *flags, int argc, char **argv);

#endif  // CPACK_INCLUDE_CLI_H_