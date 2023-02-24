#ifndef LIB_INCLUDE_FS_H_
#define LIB_INCLUDE_FS_H_

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

char *fs_read(const char *);

size_t fs_write(const char *, const char *);

size_t fs_size(const char *);

size_t fs_fsize(FILE *);

char *fs_parent(const char *);

int fs_isdir(const char *);

char **fs_scandir(const char *);

#endif  // LIB_INCLUDE_FS_H_
