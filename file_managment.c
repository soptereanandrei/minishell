#include "minishell.h"

int	mkdir_command(char **options)
{
	int	status;
	size_t	index;

	index = 1;
	while (*(options + index))
	{
		status = mkdir(*(options + index), 0700);
		if (status != 0)
		{
			write(2, "Cannot create the directory:", 29);
			write(2, *(options + index), ft_strlen(*(options + index)));
			write(2, "\n", 1);
		}
		index++;
	}
	return (1);
}

int	mv_command(char **options)
{
	int	status;

	if (!options[1] || !options[2])
		write(2, "Missing file operands\n", 23);
	else if (options[1] && options[2])
	{
		status = rename(options[1], options[2]);
		if (status != 0)
			write(2, "Cannot rename the file\n", 24);
	}
	return (1);
}

int	rm_command(char **options)
{
	int	status;
	size_t	index;

	index = 1;
	while (*(options + index))
	{
		status = remove(*(options + index));
		if (status != 0)
		{
			write(2, "Cannot delete the file:", 26);
			write(2, *(options + index), ft_strlen(*(options + index)));
			write(2, "\n", 1);
		}
		index++;
	}
	return (1);
}

int	touch_command(char **options)
{
	FILE	*file;
	size_t	index;

	index = 1;
	while (*(options + index))
	{
		file = fopen(*(options + index), "r");
		if (!file)
			file = fopen(*(options + index), "w+");
		if (!file)
		{
			write(2, "Cannot create the file:", 24);
			write(2, *(options + index), ft_strlen(*(options + index)));
			write(2, "\n", 1);
		}
		index++;
	}
	return (1);
}
