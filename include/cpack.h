#ifndef CPAC_INCLUDE_CPAC_H_
#define CPAC_INCLUDE_CPAC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "help.h"

#define OK 0
#define ERR 1

typedef enum help_page {
  Main,
  New,
} hpage_t;

/* ------------------------------------------------ */
/*    MAIN FUNCTIONS                                */
/* ------------------------------------------------ */

int cpack_exec(int argc, char *argv[]);

/* ------------------------------------------------ */
/*    SUBCOMMANDS                                   */
/* ------------------------------------------------ */

void subcmd_init();

void subcmd_new(const char *);

/* ------------------------------------------------ */
/*    UTILITY FUNCTIONS                             */
/* ------------------------------------------------ */

void print_help(hpage_t);

int check_no_args(int);

#ifdef DEBUG
void dbg_args(int argc, char *argv[]);
#endif

#endif  // CPAC_INCLUDE_CPAC_H_
