#include "cpack/error.h"
#include "filegen.h"

int create_project_folder(const char *projname) {
  result_t res = ERR;

  if (projname != NULL) {
    char *pwd = getenv("PWD"),
         *proj_folder =
             calloc(strlen(pwd) + strlen(projname) + 1, sizeof(char)),
         *src_folder = calloc(strlen(pwd) + strlen(projname) + 5, sizeof(char));

    if (proj_folder != NULL && src_folder != NULL) {
      sprintf(proj_folder, "%s/%s", pwd, projname);
      sprintf(src_folder, "%s/src", proj_folder);

      res = mkdir(proj_folder, 0777);
      if (res == OK) res = mkdir(src_folder, 0777);

      free(proj_folder);
      free(src_folder);
    }
  }

  return res;
}

int add_folder_to_project(const char *projname, const char *folder) {
  result_t res = ERR;

  if (projname != NULL && folder != NULL) {
    char *pwd = getenv("PWD"),
         *target_folder = calloc(
             strlen(pwd) + strlen(projname) + strlen(folder) + 5, sizeof(char));

    if (target_folder != NULL) {
      sprintf(target_folder, "%s/%s/%s", pwd, projname, folder);
      res = mkdir(target_folder, 0777);

      free(target_folder);
    }
  }

  return res;
}

int gen_makefile(const char *projname, const char *path, const char *content) {
  result_t res = ERR;
  char *filepath = calloc(strlen(path) + 10, sizeof(char));
  FILE *fp;

  if (projname == NULL || path == NULL || content == NULL || filepath == NULL)
    return res;

  sprintf(filepath, "%s/Makefile", path);

  if ((fp = fopen(filepath, "w")) != NULL) {
    fprintf(fp, "NAME      := %s\n%s", projname, content);
    fclose(fp);

    res = OK;
  }

  free(filepath);
  return res;
}

int gen_file(const char *path, const char *filename, const char *content) {
  result_t res = ERR;
  char *filepath = calloc(strlen(path) + strlen(filename) + 12, sizeof(char));
  FILE *fp;

  if (filename == NULL || path == NULL || filepath == NULL) return ERR;

  sprintf(filepath, "%s/%s", path, filename);

  if ((fp = fopen(filepath, "w")) != NULL) {
    fprintf(fp, "%s", content);
    fclose(fp);
    res = OK;
  }

  free(filepath);
  return res;
}
