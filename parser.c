/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:42:55 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/13 13:42:23 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "stack.h"


static void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_and_store(char *arg, t_stack *stack)
{
	int		num;
	int		i;
	char	**split;

	split = ft_split(arg, ' ');
	if (!split)
		exit_error();
	i = 0;
	while (split[i])
	{
		if (!is_number(split[i]) || !ft_atoi_secure(split[i], &num))
			exit_error();
		stack->data[stack->size++] = num;
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		parse_and_store(argv[i], stack);
		i++;
	}
	if (has_duplicates(stack))
		exit_error();
	return (1);
}
