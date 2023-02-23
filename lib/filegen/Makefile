NAME      := filegen
TARGET    := lib$(NAME).a

SRC_DIR   := src
BUILD_DIR := .build

SRC       := $(addprefix $(SRC_DIR)/, lib.c)
OBJ       := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP       := $(OBJ:.o=.d)

CC        := gcc
RM        := rm -rf
AR        := ar
CFLAGS    := -std=c11 -Wall -Wextra -Werror
CPPFLAGS  := -MMD -MP -I include -I ../../include
ARFLAGS   := -rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJ)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEP)

rebuild: clean all

clean:
	$(RM) $(TARGET) $(BUILD_DIR)
