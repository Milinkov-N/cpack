NAME      := .out

SRC_DIR   := src
BUILD_DIR := .build

SRC       := $(addprefix $(SRC_DIR)/, main.c)
OBJ       := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC        := gcc
RM        := rm -rf
CFLAGS    := -std=c11 -Wall -Wextra -Werror
ARGS       =

all: run

run: $(NAME)
	-./$(NAME) $(ARGS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

rebuild: clean $(NAME)

rerun: clean all

clean:
	$(RM) $(NAME) $(BUILD_DIR)
