#include "minishell.h"

int	help_command()
{
	char	*line;
	int	file;
	int	ret;

	file = open("manual.txt", O_RDONLY);
	while ((ret = get_next_line(file, &line)))
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	return (1);
}
