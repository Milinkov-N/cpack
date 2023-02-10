#include "cpack.h"

int main(int argc, char *argv[]) {
  if (check_no_args(argc) == ERR) return OK;

#ifdef DEBUG
  dbg_args(argc, argv);
#endif

  return cpack_exec(argc, argv);
}
