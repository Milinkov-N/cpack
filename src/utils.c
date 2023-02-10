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

int check_no_args(int argc) {
  int res = ERR;
  argc < 2 ? print_help(Main) : (res = OK);
  return res;
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
