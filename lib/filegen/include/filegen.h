#ifndef LIB_INCLUDE_FILEGEN_H_
#define LIB_INCLUDE_FILEGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "filegen/makefile.h"

int create_project_folder(const char *projname);

int add_folder_to_project(const char *projname, const char *folder);

int gen_makefile(const char *projname, const char *path, const char *content);

int gen_file(const char *path, const char *filename, const char *content);

#endif  // LIB_INCLUDE_FILEGEN_H_
