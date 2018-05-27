/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:46:56 by asoptere          #+#    #+#             */
/*   Updated: 2018/02/10 21:03:56 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list		*find_nod(t_list **list, int const fd)
{
	t_list	*nod;

	nod = *list;
	if (nod)
	{
		while (nod->next && nod->content_size != (size_t)fd)
			nod = nod->next;
		if (nod->content_size == (size_t)fd)
			return (nod);
	}
	nod = ft_lstnew(0, 0);
	nod->content_size = (size_t)fd;
	ft_lstadd(list, nod);
	return (nod);
}

static int			check_line(t_list *nod)
{
	int	i;

	i = 0;
	if (nod->content)
	{
		while (*((char*)(nod->content + i)) != '\0'
				&& *((char*)(nod->content + i)) != '\n')
			i++;
		if (*((char*)(nod->content + i)) == '\n')
			return (1);
		return (0);
	}
	return (0);
}

static int			get_line(t_list *nod, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!nod->content)
		return (0);
	while (*((char*)(nod->content + i)) != '\n'
		&& *(char*)(nod->content + i) != '\0')
		i++;
	*line = ft_strsub(nod->content, 0, i);
	if (*(char*)(nod->content + i) == '\0')
		i--;
	tmp = ft_strdup(nod->content + i + 1);
	free(nod->content);
	nod->content = tmp;
	if (*((char*)(nod->content)) == '\0')
	{
		free(nod->content);
		nod->content = 0;
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*list;
	t_list			*nod;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int			bt;

	if (fd < 0 || !line)
		return (-1);
	nod = find_nod(&list, fd);
	while (!check_line(nod))
	{
		if (!(bt = read(fd, buf, BUFF_SIZE)))
			return (get_line(nod, line));
		if (bt == -1)
			return (-1);
		buf[bt] = '\0';
		tmp = ft_strjoin(nod->content, buf);
		free(nod->content);
		nod->content = tmp;
	}
	return (get_line(nod, line));
}
