/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:33:34 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/13 00:52:21 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char	*line(char const *str, char c)
{
	int		len;
	int		i;
	char	*list;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	list = malloc(sizeof(char) * (len + 1));
	if (!list)
		return (NULL);
	i = 0;
	while (i < len)
	{
		list[i] = str[i];
		i++;
	}
	list[i] = '\0';
	return (list);
}

static char	**ft_free(char **list, int i)
{
	while (i >= 0)
	{
		free(list[i]);
		i--;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**list;

	list = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!list)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			list[i] = line(s, c);
			if (!list[i])
				return (ft_free(list, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	list[i] = NULL;
	return (list);
}
