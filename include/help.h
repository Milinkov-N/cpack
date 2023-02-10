#ifndef CPAC_INCLUDE_HELP_H_
#define CPAC_INCLUDE_HELP_H_

#define HELP_PAGE_MAIN                                                   \
  "cpack 0.1.0 (10-02-2023)\n"                                           \
  "The C Language Local Package Manager\n"                               \
  "Author: Milinkov Nikita (s21: taniakia) <milinkov.nik@gmail.com>\n\n" \
  "USAGE:\n"                                                             \
  "\tcpac [FLAGS]  <SUBCOMMAND>\n\n"                                     \
  "SUBCOMMANDS:\n"                                                       \
  "\tinit      Initialize an empty project in current folder\n"          \
  "\tnew       Create a new empty project with a given name\n"           \
  "\thelp      Prints this message\n"

#define HELP_PAGE_NEW                                \
  "cpac-new\n"                                       \
  "Create a new empty project with a given name\n\n" \
  "USAGE:\n"                                         \
  "\tcpac new  <PROJECT_NAME>\n\n"

#endif  // CPAC_INCLUDE_HELP_H_
