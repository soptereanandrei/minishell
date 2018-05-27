#include "minishell.h"

int	show_command(char **envp, char **names)
{
	char	*value;
	size_t	index;

	index = 1;
	while (*(names + index))
	{
		value = envp_search(envp, *(names + index));
		if (value)
		{
			write(1, *(names + index), ft_strlen(*(names + index)));
			write(1, "=", 1);
			write(1, value, ft_strlen(value));
			free(value);
		}
		else
		{
			write(1, *(names + index), ft_strlen(*(names + index)));
			write(1, " not found", 11);
		}
		write(1, "\n", 1);
		index++;
	}
	return (1);
}
