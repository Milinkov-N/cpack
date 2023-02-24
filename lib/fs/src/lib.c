#include "fs.h"

#define DIRENTRIES_MAX 32

char *fs_read(const char *filepath) {
  FILE *fp;
  size_t fsize;
  char *bytes;

  if (filepath == NULL || (fp = fopen(filepath, "rb")) == NULL) return 0;

  fsize = fs_fsize(fp);
  if ((bytes = calloc(fsize + 1, sizeof(char))) != NULL)
    fread(bytes, fsize, 1, fp);

  fclose(fp);
  return bytes;
}

size_t fs_write(const char *filepath, const char *content) {
  FILE *fp;
  size_t w_bytes;

  if (filepath == NULL || content == NULL ||
      (fp = fopen(filepath, "w")) == NULL)
    return 0;

  w_bytes = fprintf(fp, "%s", content);
  fclose(fp);

  return w_bytes;
}

size_t fs_size(const char *filepath) {
  FILE *fp;
  size_t fsize;

  if (filepath == NULL || (fp = fopen(filepath, "r")) == NULL) return 0;

  fseek(fp, 0, SEEK_END);
  fsize = ftell(fp);
  fclose(fp);

  return fsize;
}

size_t fs_fsize(FILE *fp) {
  size_t fsize;

  if (fp == NULL) return 0;

  fseek(fp, 0, SEEK_END);
  fsize = ftell(fp);
  rewind(fp);

  return fsize;
}

char *fs_parent(const char *path) {
  if (path == NULL) return NULL;

  char *parent = NULL, *parent_end = strrchr(path, '/');
  if (parent_end != NULL &&
      (parent = calloc((parent_end - path) + 1, sizeof(char))) != NULL)
    strncpy(parent, path, parent_end - path);

  return parent;
}

char *fs_tail(const char *path) {
  if (path == NULL) return NULL;

  char *tail = strrchr(path, '/');

  return tail == NULL ? NULL : tail + 1;
}

int fs_isdir(const char *path) {
  struct stat statbuf;
  if (path == NULL || stat(path, &statbuf) != 0) return 0;
  return S_ISDIR(statbuf.st_mode);
}

static void _rscandir(const char *path, char **entries, int *e_len) {
  if (path == NULL) return;

  struct dirent **namelist;
  int n, i = 0;
  n = scandir(path, &namelist, NULL, alphasort);

  if (n < 0) return;

  while (i < n) {
    if (i == 0 || i == 1) {
      free(namelist[i++]);
      continue;
    }

    struct stat path_stat;
    char *full_path =
        calloc(strlen(path) + strlen(namelist[i]->d_name) + 1, sizeof(char));

    stat(namelist[i]->d_name, &path_stat);

    if (full_path != NULL) {
      sprintf(full_path, "%s/%s", path, namelist[i]->d_name);

      if (fs_isdir(full_path)) {
        _rscandir(full_path, entries, e_len);
        free(full_path);
      } else if (*e_len < DIRENTRIES_MAX - 1) {
        entries[(*e_len)++] = full_path;
      }
    }

    free(namelist[i]);

    ++i;
  }

  free(namelist);
}

char **fs_scandir(const char *path) {
  char **entries = calloc(DIRENTRIES_MAX, sizeof(char));
  int len = 0;
  if (path != NULL) _rscandir(path, entries, &len);
  return entries;
}
