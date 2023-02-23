#ifndef LIB_INCLUDE_MAKEFILE_H_
#define LIB_INCLUDE_MAKEFILE_H_

#define MF_WORK_DIRS   \
  "SRC_DIR   := src\n" \
  "BUILD_DIR := .build\n\n"

#define MF_CC "CC        := gcc \n"

#define MF_RM "RM        := rm - rf\n"

#define MF_AR "AR        := ar\n"

#define MF_CFLAGS "CFLAGS    := -std=c11 -Wall -Wextra -Werror\n"

#define MF_ARGS "ARGS       =\n"

#define MF_LIB_TARGET "TARGET    := lib$(NAME).a\n\n"

#define MF_LIB_SOD_VARS                                   \
  "SRC       := $(addprefix $(SRC_DIR)/, lib.c)\n"        \
  "OBJ       := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)\n" \
  "DEP       := $(OBJ:.o=.d)\n\n"

#define MF_LIB_FLAGS                   \
  MF_CFLAGS                            \
  "CPPFLAGS  := -MMD -MP -I include\n" \
  "ARFLAGS   := -rcs\n\n"

#define MF_LIB_BUILD_RULES                               \
  "all: $(NAME)\n\n"                                     \
  "$(NAME): $(OBJ)\n"                                    \
  "\t$(AR) $(ARFLAGS) $(TARGET) $(OBJ)\n"                \
  "\t$(info CREATED $@)\n\n"                             \
  "$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c\n"                   \
  "\tmkdir -p $(@D)\n"                                   \
  "\t$(CC) $(CFLAGS) $(CPPFLAGS) $(DEBUG) -c -o $@ $<\n" \
  "\t$(info CREATED $@)\n\n"                             \
  "rebuild: clean all\n\n"                               \
  "clean:\n"                                             \
  "\t$(RM) $(NAME) $(BUILD_DIR)\n"

#define MF_BIN_RULES                        \
  "all: run\n\n"                            \
  "run: $(NAME)\n"                          \
  "\t-./$(NAME) $(ARGS)\n\n"                \
  "$(NAME): $(OBJ)\n"                       \
  "\t$(CC) $(CFLAGS) $(OBJ) -o $(NAME)\n\n" \
  "$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c\n"      \
  "\tmkdir -p $(@D)\n"                      \
  "\t$(CC) $(CFLAGS) -c -o $@ $<\n\n"       \
  "rebuild: clean $(NAME)\n\n"              \
  "rerun: clean all\n\n"                    \
  "clean:\n"                                \
  "\t$(RM) $(NAME) $(BUILD_DIR)\n"

#define MF_LIB_CONTENTS \
  MF_LIB_TARGET         \
  MF_WORK_DIRS          \
  MF_LIB_SOD_VARS       \
  MF_CC                 \
  MF_RM                 \
  MF_AR                 \
  MF_LIB_FLAGS          \
  MF_LIB_BUILD_RULES

#define MF_BIN_CONTENTS                                                 \
  MF_WORK_DIRS                                                          \
  "SRC       := $(addprefix $(SRC_DIR)/, main.c)\n"                     \
  "OBJ       := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)\n\n" MF_CC MF_RM \
      MF_CFLAGS MF_ARGS "\n" MF_BIN_RULES

#endif  // LIB_INCLUDE_MAKEFILE_H_
