#ifndef CPACK_INCLUDE_HELP_H_
#define CPACK_INCLUDE_HELP_H_

#define HELP_USAGE_NEW \
  "USAGE:\n"           \
  "\tcpack new <PROJECT_NAME> [--lib | --bin | -t<TEMPLPATE>]\n\n"

#define HELP_USAGE_INIT \
  "USAGE:\n"            \
  "\tcpack init [--lib | --bin | -t<TEMPLPATE>]\n\n"

#define HELP_PAGE_MAIN                                                   \
  "cpack 0.1.0 (10-02-2023)\n"                                           \
  "The C Language Local Package Manager\n"                               \
  "Author: Milinkov Nikita (s21: taniakia) <milinkov.nik@gmail.com>\n\n" \
  "USAGE:\n"                                                             \
  "\tcpack <SUBCOMMAND> [FLAGS]\n\n"                                     \
  "SUBCOMMANDS:\n"                                                       \
  "\tinit      Initialize an empty project in current folder\n"          \
  "\tnew       Create a new empty project with a given name\n"           \
  "\thelp      Prints this message\n"

#define HELP_PAGE_NEW \
  "cpack-new\n"       \
  "Create a new empty project with a given name\n\n" HELP_USAGE_NEW

#endif  // CPACK_INCLUDE_HELP_H_
