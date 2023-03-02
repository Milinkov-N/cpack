NAME        := cpack

SRC_DIR     := src
BUILD_DIR   := .build
INST_DIR    := $(HOME)/.$(NAME)

LIBS        := fs
LIBNAMES    := $(addprefix lib,$(LIBS))
LIBS_TARGET := lib/fs/libfs.a
LIBS_INC    := $(LIBS:%=lib/%/include)
INCS        := include $(LIBS_INC)

SRC         := $(addprefix $(SRC_DIR)/, cpack.c cli.c main.c)
OBJ         := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP         := $(OBJ:.o=.d)

CC          := gcc
RM          := rm -rf
CFLAGS      := -std=c11 -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(addprefix -l,$(LIBS))
MAKEFLAGS   += --silent

ARGS       =
DEBUG      = # yes/no

all: run

run: $(NAME)
	-./$(NAME) $(ARGS)

debug:
	$(MAKE) rebuild DEBUG=yes

$(NAME): $(LIBS_TARGET) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	$(info CREATED $@)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)

	if [ "$(DEBUG)" = "yes" ]; then \
        $(CC) $(CFLAGS) $(CPPFLAGS) -DDEBUG -c -o $@ $<; \
    else \
        $(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<; \
    fi
	
	$(info CREATED $@)

-include $(DEP)

install: $(NAME) add-alias
	@mkdir $(INST_DIR)
	@cp $(NAME) $(INST_DIR)
	@cp .production.env $(INST_DIR)
	$(MAKE) add-source-env
	@cp -R templates $(INST_DIR)
	$(info INSTALLED CPack)

add-alias:
	if [[ -z "$$(grep "alias cpack="\$$HOME/.cpack/cpack"" ~/.zshrc)" ]]; then \
		printf "\n# CPack exec alias\nalias cpack=\$$HOME/.cpack/cpack\n" >> ~/.zshrc; \
	fi

add-source-env:
	if [[ -z "$$(grep "source \$$HOME/.cpack/.production.env" ~/.zshrc)" ]]; then \
		printf "\n# Load CPack env\nsource \$$HOME/.cpack/.production.env\n" >> ~/.zshrc; \
	fi
	source $$HOME/.cpack/.production.env

uninstall:
	$(RM) $(INST_DIR)
	$(info UNINSTALLED CPack)

reinstall: uninstall install

rebuild: clean $(NAME)

rerun: clean all

clean: $(LIBS:%=%-clean)
	$(RM) $(NAME) $(BUILD_DIR)

%-clean:
	$(MAKE) -C lib/$* clean
