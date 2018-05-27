#include "minishell.h"

char	*envp_search(char **envp, char *name)
{
	size_t	index;

	index = 0;
	if (envp)
	{
		while (*(envp + index))
		{
			if (ft_strnstr(*(envp + index), name, ft_strlen(name)))
				return (ft_strdup(*(envp + index) + ft_strlen(name) + 1));
			index++;
		}
	}
	return (0);
}
/*
void	preparation(char ***envp)
{
	char	**options;
	char	*pwd;
	char	*aux;
	
	options = (char**)malloc(sizeof(char*) * 3);
	*options = 0;
	*(options + 2) = 0;
	*(options + 1) = ft_strdup("SHELL");
	unsetenv_command(envp, options);
	free(*(options + 1));
	pwd = envp_search(*envp, "PWD");
	aux = ft_strjoin(pwd, "ft_minishell1");
	free(pwd);
	pwd = aux;
	aux = ft_strjoin("SHELL=", pwd);
	free(pwd);
	pwd = aux;
	*(options + 1) = pwd;
	setenv_command(options, envp);
	free(*(options + 1));
	free(options);
}*/

int	is_builtin(char *command, char **options, char ***envp)
{
	if (ft_strequ(command, "cd"))
	{
		cd_command(options, *envp);
		return (1);
	}
	else if (ft_strequ(command, "setenv"))
	{
		setenv_command(options, envp);
		return (1);
	}
	else if (ft_strequ(command, "unsetenv"))
	{
		unsetenv_command(envp, options);
		return (1);
	}
	else if (ft_strequ(command, "env"))
	{
		env_command(*envp, options);
		return (1);
	}
	else if (ft_strequ(command, "exit"))
		exit(0);
	else
		return (functions(command, options, envp));
}

void	free_command(char *command, char **options)
{
	int	i;

	free(command);
	i = 0;
	if (options)
	{
		while (*(options + i))
			free(*(options + i++));
		free(options);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char 		*command;
	char		**options;
	int		ret;

	if (argc && argc && envp)
	while (1)
	{
		write(1, "$>", 2);
		ret = get_next_line(0, &command);
		if (ret > -1)
		{
			options = ft_strsplit(command, ' ');
			if (options)
			{
				command = options[0];
				options[0] = ft_strdup(argv[0]);
				if (!is_builtin(command, options, &envp))
					manage_process(command, options, envp);
				free_command(command, options);
			}
		}
		else
			write(2, "Read error!\n", 12);
	}
}
// STATIC FUNCTIONS!!!!
