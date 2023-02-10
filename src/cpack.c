#include "cpack.h"

result_t cpack_exec(state_t *state) {
  if (!strcmp(state->argv[1], "init"))
    subcmd_init(&state->flags);
  else if (!strcmp(state->argv[1], "new") && state->argc > 2)
    subcmd_new(state->argv[2], &state->flags);
  else
    print_help(Main);

  return OK;
}
