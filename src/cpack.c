#include "cpack.h"

int cpack_exec(int argc, char *argv[]) {
  check_no_args(argc);
  if (!strcmp(argv[1], "init"))
    subcmd_init();
  else if (!strcmp(argv[1], "new") && argc > 2)
    subcmd_new(argv[2]);
  else
    print_help(Main);

  return OK;
}
