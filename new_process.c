#include "minishell.h"

char	*get_path(char *path, char *process)
{
	char	*complet_path;
	size_t	size1;
	size_t	size2;

	size1 = ft_strlen(path);
	size2 = ft_strlen(process);
	complet_path = (char*)malloc(sizeof(char) * (size1 + size2 + 2));
	ft_strcpy(complet_path, path);
	complet_path[size1] = '/';
	ft_strcpy(complet_path + size1 + 1, process);
	return (complet_path);
}

char	**find_path(char **envp)
{
	char	*line;
	int	index;

	index = 0;
	while (envp[index])
	{
		if (ft_strnstr(envp[index], "PATH=", 5))
		{
			line = envp[index];
			line = line + 5;
			return (ft_strsplit(line, ':'));
		}
		index++;
	}
	return (0);
}

void	start_process(char *process, char **options, char **envp)
{
	char	**path;
	char	*line;
	int	index;

	if ((path = find_path(envp)))
	{
		index = 0;
		while (path[index])
		{
			line = get_path(path[index], process);
			execve(line, options, envp);
			index++;
		}
	}
	execve(process, options, envp);
}

void	manage_process(char *process, char **options, char **envp)
{
	pid_t	_pid;
	int	wstatus;

	_pid = fork();
	if (_pid >= 0)
	{
		if (_pid > 0)
			wait(&wstatus);
		if (_pid == 0)
		{
			start_process(process, options, envp);
			ft_putstr(process);
			write(2, ": command not found\n", 20);
		}
	}
	else
		write(2, "Cannot start a new process\n", 27);
}

//int	restart_command()
//{
//	
//}
