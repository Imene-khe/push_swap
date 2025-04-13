/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:14:03 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/12 23:47:55 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "stack.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->data);
		free(stack);
	}
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size <= 1)
		return (1);
	while (i < stack->size - 1)
	{
		if (stack->data[i + 1] > stack->data[i])
			return (0);
		i ++;
	}
	return (1);
}
