#include "cpack.h"

int main(int argc, char *argv[]) {
  if (check_no_args(argc) == ERR) return OK;

#ifdef DEBUG
  dbg_args(argc, argv);
#endif

  state_t state = {argc, argv, {{0}, 0}};

  switch (parse_flags(&state)) {
    case ERR_PROJECT_TYPE:
      fprintf(stderr, ERRMSG_PROJECT_TYPE);
      break;
    case ERR:
      fprintf(stderr, ERRMSG_UNEXPECTED);
      break;
    default:
      return cpack_exec(&state);
  }
}
