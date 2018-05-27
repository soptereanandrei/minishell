#ifndef MINISHELL_H

# define MINISHELL_H
# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>//delete

char	*envp_search(char **envp, char *name);
void	manage_process(char *process, char **options, char **envp);
void	cd_command(char **options, char **envp);
void	setenv_command(char **options, char ***envp);
void	unsetenv_command(char ***envp, char **options);
void	env_command(char **envp, char **options);
int	echo_command(char **argument);
int	show_command(char **envp, char **names);
int	touch_command(char **options);
int	rm_command(char **options);
int	mv_command(char **options);
int	mkdir_command(char **options);
int	functions(char *command, char **options, char ***envp);
int	help_command();

#endif
