#include "cpack.h"

result_t cpack_create_project(char *projname, char *template) {
  char **entries;
  const char *tmp_root = getenv("CPACK_TMP_PATH");
  char *tmp = calloc(strlen(tmp_root) + strlen(template) + 1, sizeof(char));

  if (projname == NULL || template == NULL || tmp == NULL) return ERR;
  if (strcmp(projname, ".") && cpack_create_project_folder(projname)) {
    free(tmp);
    return ERR_CR_PROJ_FOLDER;
  }

  sprintf(tmp, "%s/%s", tmp_root, template);

  if ((entries = fs_scandir(tmp)) == NULL) {
    free(tmp);
    return ERR_TEMP_NOT_FOUND;
  }

  char **p = entries;

  while (*p != NULL) {
    int res = 0;
    cpack_add_tmp_folder_to_proj(projname, tmp, *p);
    char *content = fs_read(*p),
         *filepath = cpack_gen_filepath(projname, *p, tmp);

    if (content != NULL && filepath != NULL && !res) {
      fs_write(filepath, content);
      free(filepath);
      free(content);
    }

    free(*(p++));
  }

  free(entries);

  return OK;
}

result_t cpack_create_project_folder(const char *name) {
  return !mkdir(name, 0777) ? OK : ERR_CR_PROJ_FOLDER;
}

void cpack_add_tmp_folder_to_proj(const char *projname, const char *tmp_path,
                                  const char *entry) {
  char *dir;

  if (projname == NULL || entry == NULL) return;
  if ((dir = fs_parent(entry + strlen(tmp_path) + 1)) == NULL) return;

  char *path = calloc(strlen(projname) + strlen(dir) + 1, sizeof(char));
  if (path != NULL) {
    sprintf(path, "%s/%s", projname, dir);
    mkdir(path, 0777);
    free(path);
  }

  free(dir);
}

char *cpack_strip_tmp_name(char *path, char *tmp_name) {
  if (path == NULL || tmp_name == NULL) return NULL;

  return path + strlen(tmp_name) + 1;
}

char *cpack_gen_filepath(char *projname, char *entry, char *tmp_name) {
  char *filepath = NULL, *finalpath = NULL;
  if (projname == NULL || entry == NULL || tmp_name == NULL) return NULL;

  filepath = cpack_strip_tmp_name(entry, tmp_name);
  finalpath = calloc(strlen(projname) + strlen(filepath) + 1, sizeof(char));

  if (filepath != NULL && finalpath != NULL)
    sprintf(finalpath, "%s/%s", projname, filepath);

  return finalpath;
}
