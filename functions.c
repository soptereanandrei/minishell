#include "minishell.h"

int	functions(char *command, char **options, char ***envp)
{
	if (options)
	{
		if (ft_strequ("clear", command))
		{
			system("clear");
			return (1);
		}
		else if (ft_strequ("echo", command))
			return (echo_command(options));
		else if (ft_strequ("show", command))
			return (show_command(*envp, options));
		else if (ft_strequ("touch", command))
			return (touch_command(options));
		else if (ft_strequ("rm", command))
			return (rm_command(options));
		else if (ft_strequ("mv", command))
			return (mv_command(options));
		else if (ft_strequ("mkdir", command))
			return (mkdir_command(options));
		else if (ft_strequ("help", command) || ft_strequ("man", command)
				|| ft_strequ("manual", command))
			return (help_command());
	}
	return (0);
}
