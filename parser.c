/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:42:55 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/20 14:31:14 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "stack.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_args(int argc, char **argv, t_stack *stack)
{
	char	**split;
	int		i;
	int		j;
	int		num;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			exit_error();
		j = 0;
		while (split[j])
		{
			if (!is_number(split[j]) || !ft_atoi_secure(split[j], &num))
				exit_error();
			stack->data[stack->size++] = num;
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	if (has_duplicates(stack))
		exit_error();
}
