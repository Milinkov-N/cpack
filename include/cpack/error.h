#ifndef CPACK_INCLUDE_ERROR_H_
#define CPACK_INCLUDE_ERROR_H_

#define OK 0x0
#define ERR 0x01
#define ERR_PROJECT_TYPE 0x02

#define ERRMSG_PROJECT_TYPE                                         \
  "Error: Only --lib or --bin flag can be given at the same time\n" \
  "USAGE:\n"                                                        \
  "\tcpack <SUBCOMMAND> [--lib | --bin]\n"

#define ERRMSG_UNEXPECTED "Error: Unexpected error occurred\n"

typedef int result_t;

#endif  // CPACK_INCLUDE_ERROR_H_