NAME      := cpack

INC       := include

SRC_DIR   := src
BUILD_DIR := .build
INST_DIR  := $(HOME)/.$(NAME)

SRC       := $(addprefix $(SRC_DIR)/, main.c cpack.c subcmd.c utils.c)
OBJ       := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP       := $(OBJ:.o=.d)

CC        := gcc
RM        := rm -rf
CFLAGS    := -std=c11 -Wall -Wextra -Werror
CPPFLAGS  := $(addprefix -I,$(INC)) -MMD -MP
MAKEFLAGS += --silent

ARGS       =
DEBUG      = # yes/no

all: run

run: $(NAME)
	-./$(NAME) $(ARGS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)

	if [ "$(DEBUG)" = "yes" ]; then \
        $(CC) $(CFLAGS) $(CPPFLAGS) -DDEBUG -c -o $@ $<; \
    else \
        $(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<; \
    fi
	
	$(info CREATED $@)

-include $(DEP)

install: $(NAME)
	@mkdir $(INST_DIR)
	@cp $(NAME) $(INST_DIR)
	@cp -R templates $(INST_DIR)
	$(info INSTALLED CPack)

uninstall:
	$(RM) $(INST_DIR)
	$(info UNINSTALLED CPack)

reinstall: uninstall install

rebuild: clean $(NAME)

rerun: clean all

clean:
	$(RM) $(NAME) $(BUILD_DIR)
