#ifndef CPACK_INCLUDE_CPACK_H_
#define CPACK_INCLUDE_CPACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "cpack/error.h"
#include "cpack/help.h"
#include "filegen.h"

#define TRUE 1
#define FALSE 0

#define ENABLE 1
#define DISABLE 0

typedef int bool_t;

typedef enum help_page {
  Main,
  New,
} hpage_t;

typedef struct flags {
  char proj_type[16];
  char git;
} flags_t;

typedef struct app_state {
  int argc;
  char **argv;
  flags_t flags;
} state_t;

/* ------------------------------------------------ */
/*    MAIN FUNCTIONS                                */
/* ------------------------------------------------ */

int cpack_exec(state_t *state);

/* ------------------------------------------------ */
/*    SUBCOMMANDS                                   */
/* ------------------------------------------------ */

void subcmd_init(flags_t *);

void subcmd_new(const char *, flags_t *);

/* ------------------------------------------------ */
/*    UTILITY FUNCTIONS                             */
/* ------------------------------------------------ */

void print_help(hpage_t);

int check_no_args(int);

int parse_flags(state_t *state);

#ifdef DEBUG
void dbg_args(int argc, char *argv[]);

void dbg_flags(flags_t *flags);
#endif

#endif  // CPACK_INCLUDE_CPACK_H_
