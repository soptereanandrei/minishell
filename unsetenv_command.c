#include "minishell.h"

int	check_unsetenv_options(char **options)
{
	if (!options[1])
		return (0);
	return (1);
}

void	unsetenv_command(char ***envp, char **options)
{
	int	index_o;
	int	index_e;

	if (!check_unsetenv_options(options))
		*envp = 0;
	else
	{
		index_o = 1;
		while (options[index_o])
		{
			index_e = 0;
			while (*(*envp + index_e))
			{
				if (ft_strnstr(*(*envp + index_e), options[index_o],
							ft_strlen(options[index_o])))
						*(*envp + index_e) = 0;
				index_e++;
			}
			index_o++;
		}
	}
}
