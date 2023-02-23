#include "cpack.h"

static result_t create_lib(const char *projname) {
  result_t res = ERR;
  char *pwd = getenv("PWD"),
       *proj_folder = calloc(strlen(pwd) + strlen(projname) + 3, sizeof(char));

  if (projname == NULL || proj_folder == NULL) return ERR;

  sprintf(proj_folder, "%s/%s", pwd, projname);

  res = create_project_folder(projname);
  if (res == OK) res = add_folder_to_project(projname, "include");
  if (res == OK) res = gen_makefile(projname, proj_folder, MF_LIB_CONTENTS);
  if (res == OK)
    res = gen_file(proj_folder, "src/lib.c",
                   "#include \"self.h\"\n\n"
                   "void print_hello() { "
                   "printf(\"Hello, World!\\n\"); }\n");
  if (res == OK)
    res = gen_file(proj_folder, "include/self.h",
                   "#ifndef PROJECTNAME_INCLUDE_PROJECTNAME_H_\n"
                   "#define PROJECTNAME_INCLUDE_PROJECTNAME_H_\n\n"
                   "#include <stdio.h>\n\n"
                   "void print_hello();\n\n"
                   "#endif  // PROJECTNAME_INCLUDE_PROJECTNAME_H_\n");

  return res;
}

static result_t create_bin(const char *projname) {
  result_t res = ERR;
  char *pwd = getenv("PWD"),
       *proj_folder = calloc(strlen(pwd) + strlen(projname) + 3, sizeof(char));

  if (projname == NULL || proj_folder == NULL) return ERR;

  sprintf(proj_folder, "%s/%s", pwd, projname);

  res = create_project_folder(projname);
  if (res == OK) res = gen_makefile(projname, proj_folder, MF_BIN_CONTENTS);
  if (res == OK)
    res = gen_file(proj_folder, "src/main.c",
                   "#include <stdio.h>\n\n"
                   "int main(void) {\n"
                   "  printf(\"Hello, World!\\n\");\n"
                   "  return 0;\n}\n");

  return res;
}

static void create_project(const char *projname, flags_t *flags) {
  result_t res = ERR;
  char git[96] = {0}, *template = flags->proj_type;

  if (projname != NULL) {
    if (!strcmp(template, "lib"))
      res = create_lib(projname);
    else
      res = create_bin(projname);
    sprintf(git, "git init $PWD/%.64s", projname);
  } else {
    // TODO: Not working

    if (!strcmp(template, "lib"))
      res = create_lib("");
    else
      res = create_bin("");
    sprintf(git, "git init $PWD");
  }

  if (res == OK && flags->git) system(git);

  if (res == OK && projname != NULL) {
    printf("Created new project %s\n", projname);
  } else if (res == OK) {
    printf("Initialized new project\n");
  } else {
    printf(ERRMSG_UNEXPECTED);
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
