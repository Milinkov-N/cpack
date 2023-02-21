#include "cpack.h"

static void create_project(const char *projname, flags_t *flags) {
  char cmd[128] = {0}, git[96] = {0}, *template = flags->proj_type;

  if (projname != NULL) {
    sprintf(cmd, "cp -R $HOME/.cpack/templates/%.3s $PWD/%.64s", template,
            projname);
    sprintf(git, "git init $PWD/%.64s", projname);
  } else {
    sprintf(cmd, "cp -R $HOME/.cpack/templates/%.3s/* $PWD", template);
    sprintf(git, "git init $PWD");
  }

  system(cmd);
  if (flags->git) system(git);

  if (projname != NULL) {
    printf("Created new project %s\n", projname);
  } else {
    printf("Initialized new project\n");
  }
}

void subcmd_init(flags_t *flags) { create_project(NULL, flags); }

void subcmd_new(const char *projname, flags_t *flags) {
  if (projname == NULL) {
    print_help(New);
    return;
  }

  create_project(projname, flags);
}
