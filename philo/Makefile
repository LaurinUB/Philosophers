CC = cc
NAME = philo
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
DIR_DUP = mkdir -p $(@D)

SRC = main.c util.c
SRC := $(SRC:%=$(SRC_DIR)/%)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LINK_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

