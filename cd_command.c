#include "minishell.h"

void	free_var(char *pwd, char *new_pwd)
{
	free(pwd);
	free(new_pwd);
}

void	go_home(char **envp)
{
	int	index;
	char	*line;

	index = 0;
	while (envp[index])
	{
		if (ft_strnstr(envp[index], "HOME=", 5))
		{
			line = envp[index];
			line = line + 5;
			chdir(line);
			return ;
		}
		index++;
	}
}

void	cd_command(char **options, char **envp)
{
	char	*pwd;
	char	*new_pwd;

	pwd = (char*)malloc(1000);
	new_pwd = (char*)malloc(1000);
	if (options[1])
	{
		if (options[2])
			write(2, "cd: too many arguments\n", 23);
		else
		{
			getcwd(pwd, 1000);
			chdir(options[1]);
			getcwd(new_pwd, 1000);
			if (ft_strequ(pwd, new_pwd))
			{
				ft_putstr(options[1]);
				write(2, ": No such file or directory\n", 28);
			}
		}
	}
	else
		go_home(envp);
	free_var(pwd, new_pwd);
}
