#include "minishell.h"

void	print_env(char **envp)
{
	int	index;

	index = 0;
	if (envp)
		while (envp[index])
		{
			ft_putstr(envp[index++]);
			write(1, "\n", 1);
		}
}

char	**get_envp(char **options, int *poz, char **name)
{
	char	**envp_to_start;
	int	index1;
	int	index2;

	index1 = 1;
	while (ft_strchr(options[index1], '='))
		index1++;
	*name = (char*)malloc(ft_strlen(options[index1]) + 1);
	ft_strcpy(*name, options[index1]);
	*(*name + ft_strlen(options[index1])) = '\0';
	envp_to_start = (char**)malloc(sizeof(char*) * index1);
	index2 = 1;
	while (index2 < index1)
	{
		envp_to_start[index2-1] = (char*)malloc(ft_strlen(options[index2]) + 1);
		ft_strcpy(envp_to_start[index2-1], options[index2]);
		envp_to_start[index2-1][ft_strlen(options[index2])] = '\0';
		index2++;
	}
	envp_to_start[index1-1] = 0;
	*poz = index1;
	return (envp_to_start);
}

char	**get_args(char **options, int poz)
{
	char	**args;
	int	index;
	int	index2;
	int	index3;

	index = poz + 1;
	while (options[index])
		index++;
	args = (char**)malloc(sizeof(char*) * (index - poz + 1));
	index2 = poz + 1;
	index3 = 1;
	while (index2 < index)
	{
		args[index3] = (char*)malloc(ft_strlen(options[index2]) + 1);
		ft_strcpy(args[index3], options[index2]);
		args[index3][ft_strlen(options[index2])] = '\0';
		index2++;
		index3++;
	}
	args[index - poz] = 0;
	return (args);
}

void	to_print(char **ptr)
{
	int i;

	i = 0;
	while (*(ptr + i))
		printf("%s\n", *(ptr + i++));
}

void	env_command(char **envp, char **options)
{
	char	**envp_to_start;
	char	**args;
	char	*name;
	int	index;

	if (!options[1])
		print_env(envp);
	else
	{
		envp_to_start = get_envp(options, &index, &name);
		args = get_args(options, index);
		args[0] = options[0];
		if (!envp_to_start[0])
			envp_to_start = envp;
		manage_process(name, args, envp_to_start);
	}
}
