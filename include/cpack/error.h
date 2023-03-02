#ifndef CPACK_INCLUDE_ERROR_H_
#define CPACK_INCLUDE_ERROR_H_

#define OK 0x0
#define ERR 0x01
#define ERR_PROJECT_TYPE 0x02
#define ERR_CR_PROJ_FOLDER 0x04
#define ERR_TEMP_NOT_FOUND 0x08

#define ERR_UNKNOWN_FLAG 0x10
#define ERR_MULTIPLE_TEMPLATES 0x20

#define ERRMSG_PROJECT_TYPE                                         \
  "Error: Only --lib or --bin flag can be given at the same time\n" \
  "USAGE:\n"                                                        \
  "\tcpack <SUBCOMMAND> [--lib | --bin]\n"

#define ERRMSG_UNEXPECTED "Error: Unexpected error occurred\n"

typedef int result_t;

#endif  // CPACK_INCLUDE_ERROR_H_
