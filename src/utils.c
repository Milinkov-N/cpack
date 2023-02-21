#include "cpack.h"

void print_help(hpage_t page) {
  switch (page) {
    case Main:
      printf(HELP_PAGE_MAIN);
      break;
    case New:
      printf(HELP_PAGE_NEW);
      break;
  }
}

result_t check_no_args(int argc) {
  int res = ERR;
  argc < 2 ? print_help(Main) : (res = OK);
  return res;
}

result_t parse_flags(state_t *state) {
  if (state == NULL) return ERR;

  bool_t is_bin = FALSE, is_lib = FALSE;

  for (int i = 0; i < state->argc; i++)
    if (!strcmp(state->argv[i], "--lib")) {
      sprintf(state->flags.proj_type, "lib");
      is_lib = TRUE;
    } else if (!strcmp(state->argv[i], "--bin")) {
      sprintf(state->flags.proj_type, "bin");
      is_bin = TRUE;
    } else if (!strcmp(state->argv[i], "--git")) {
      state->flags.git = ENABLE;
    }

  if (is_bin && is_lib) return ERR_PROJECT_TYPE;

  if (!strlen(state->flags.proj_type)) sprintf(state->flags.proj_type, "bin");

#ifdef DEBUG
  dbg_flags(&state->flags);
#endif

  return OK;
}

#ifdef DEBUG
void dbg_args(int argc, char *argv[]) {
  printf("Args {\n  argc: %d,\n  argv: [", argc);
  for (int i = 0; i < argc; i++)
    if (i < argc - 1)
      printf("\"%s\", ", argv[i]);
    else
      printf("\"%s\"]\n}\n", argv[i]);
}
#endif

#ifdef DEBUG
void dbg_flags(flags_t *flags) {
  if (flags == NULL) return;
  printf("Flags {\n  proj_type: %s\n}\n", flags->proj_type);
}
#endif
