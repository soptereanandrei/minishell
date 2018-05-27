#include "minishell.h"

void	create(char ***envp, char *var, char *value)
{
	char	**new_envp;
	int	index;

	index = 0;
	while (*(*envp + index))
		index++;
	new_envp = (char**)malloc(sizeof(char*) * (index + 2));
	index = 0;
	while (*(*envp + index))
	{
		*(new_envp + index) = *(*envp + index);
		index++;
	}
	*(new_envp + index) = (char*)malloc(ft_strlen(var) + ft_strlen(value) + 1);
	ft_strcpy(new_envp[index], var);
	ft_strcpy(new_envp[index] + ft_strlen(var), value);
	new_envp[index][ft_strlen(var) + ft_strlen(value)] = '\0';
	new_envp[index+1] = 0;
	*envp = new_envp;
	free(var);
	free(value);
}

void	put(char ***envp, int poz, char *var, char *value)
{
	char	*new_var;
	
	new_var = (char*)malloc(ft_strlen(*(*envp + poz)) + ft_strlen(value) + 2);
	ft_strcpy(new_var, *(*envp + poz));
	if (ft_strlen(*(*envp + poz)) == ft_strlen(var))
	{
		ft_strcpy(new_var + ft_strlen(var), value);
		new_var[ft_strlen(var) + ft_strlen(value)] = '\0';
	}
	else
	{
		new_var[ft_strlen(*(*envp + poz))] = ':';
		ft_strcpy(new_var + ft_strlen(*(*envp + poz)) + 1, value);
		new_var[ft_strlen(*(*envp + poz)) + ft_strlen(value) + 1] = '\0';
	}
	*(*envp + poz) = new_var;
}

char	*get_value(char **options)
{
	char	*value;
	int	index;
	int	size;

	value = 0;
	index = 2;
	size = 0;
	while (options[index])
	{
		size += ft_strlen(options[index]) + 1;
		index++;
	}
	value = (char*)malloc(sizeof(char) * size);
	index = 2;
	size = 0;
	while (options[index])
	{
		ft_strcpy(value + size, options[index]);
		size += ft_strlen(options[index]);
		value[size++] = ':';
		index++;
	}
	if (value && size > 0)
		value[size-1] = '\0';
	return (value);
}

int	setenv_check_arguments(char **options)
{
	if (!options[1])
	{
		write(2, "Usage: setenv NAME [...[[VALUE1] VALUE2] ...]\n", 47);
		return (0);
	}
	else if (!options[2])
		return (1);
	return (2);
}

void	setenv_command(char **options, char ***envp)
{
	int	poz;
	int	index;
	char	*var;

	if (setenv_check_arguments(options))
	{
		poz = -1;
		index = 0;
		var = (char*)malloc(sizeof(char) * (ft_strlen(options[1]) + 2));
		ft_strcpy(var, options[1]);
		var[ft_strlen(options[1])] = '=';
		var[ft_strlen(options[1]) + 1] = '\0';
		while (*(*envp + index))
		{
			if (ft_strnstr(*(*envp + index), var, ft_strlen(var)))
				poz = index;
			index++;
		}
		if (poz == -1)
		   create(envp, var, get_value(options));
		else if (setenv_check_arguments(options) == 2) 
		   put(envp, poz, var, get_value(options));
	}
}
