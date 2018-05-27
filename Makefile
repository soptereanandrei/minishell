NAME = ft_minishell1
CFLAGS = -Wall -Werror -Wextra
SOURCE = minishell.c new_process.c cd_command.c setenv_command.c unsetenv_command.c env_command.c echo_command.c show_command.c file_managment.c functions.c help_command.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(CFLAGS) -c $(SOURCE) -I libft/
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean $(NAME)
