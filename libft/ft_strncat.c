/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:00:10 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 18:18:28 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (*(s2 + j) && j < n)
	{
		*(s1 + i) = *(s2 + j);
		i++;
		j++;
	}
	*(s1 + i) = '\0';
	return (s1);
}
