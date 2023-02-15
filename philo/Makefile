CC = cc
NAME = philo
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
DIR_DUP = mkdir -p $(@D)

SRC = main.c \
	  	util.c \
		input.c \
		struct.c \
		struct_free.c \
		state.c \
		color.c

SRC := $(SRC:%=$(SRC_DIR)/%)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

LSANLIB = /LeakSanitizer/liblsan.a
lsan: CFLAGS += -ILeakSanitizer -Wno-gnu-include-next
lsan: LINK_FLAGS += -LLeakSanitizer -llsan -lc++
lsan: fclean $(LSANLIB)
lsan: all

$(LSANLIB):
	@if [ ! -d "LeakSanitizer" ]; then git clone https://github.com/mhahnFr/LeakSanitizer.git; fi
	@$(MAKE) -C LeakSanitizer

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

