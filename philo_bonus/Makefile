CC = cc
NAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
DIR_DUP = mkdir -p $(@D)

SRC = main_bonus.c \
	  input_bonus.c \
	  struct_bonus.c \
	  struct_free_bonus.c \
	  util_bonus.c \
	  state_bonus.c \
	  sem_utils_bonus.c \
	  child_bonus.c

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
	rm -rf LeakSanitizer

re: fclean all

.PHONY: all clean fclean re
