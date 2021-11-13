NAME = lista

CC = clang
CFLAGS = -c -Wall -Werror -Wextra

SRCS = sources/ft_main.c sources/ft_utils.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) -o $(NAME)
		@echo "Successfully compiled!"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -rf $(OBJ)
	@echo "$(OBJ) was erased!"

fclean: clean
		@rm -rf $(NAME)
		@echo "$(NAME) was erased!"

re: fclean all