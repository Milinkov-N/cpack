#include "cpack.h"

static void create_project(const char *projname) {
  char cmd[128] = {0}, git[96] = {0};

  if (projname != NULL) {
    sprintf(cmd, "cp -R $HOME/.cpack/templates/bin $PWD/%.64s", projname);
    sprintf(git, "git init $PWD/%.64s", projname);
  } else {
    sprintf(cmd, "cp -R $HOME/.cpack/templates/bin/* $PWD");
    sprintf(git, "git init $PWD");
  }

  system(cmd);
  system(git);

  if (projname != NULL) {
    printf("Created new project %s\n", projname);
  } else {
    printf("Initialized new project\n");
  }
}

void subcmd_init() { create_project(NULL); }

void subcmd_new(const char *projname) {
  if (projname == NULL) {
    print_help(New);
    return;
  }

  create_project(projname);
}
