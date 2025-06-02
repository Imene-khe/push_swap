/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:33:34 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/25 11:01:07 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*alloc_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**out;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	out = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!out)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			out[i] = alloc_word(s, c);
			if (!out[i])
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	out[i] = NULL;
	return (out);
}

int	count_total_numbers(int argc, char **argv)
{
	int		count;
	int		i;
	int		j;
	char	**split;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			exit_error();
		j = 0;
		while (split[j])
		{
			count++;
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (count);
}
