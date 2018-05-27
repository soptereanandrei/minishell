#include "minishell.h"

int	echo_command(char **argument)
{
	size_t	index;

	index = 1;
	if (argument)
		while (*(argument + index))
		{
			write(1, *(argument + index), ft_strlen(*(argument + index)));
			write(1, " ", 1);
			index++;
		}
	write(1, "\n", 1);
	return (1);
}
