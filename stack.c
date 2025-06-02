/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:46:05 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/25 10:45:21 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "stack.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp;
}

void	push_to(t_stack *from, t_stack *to)
{
	int	i;

	i = 0;
	if (from->size == 0)
		return ;
	i = to->size;
	while (i > 0)
	{
		to->data[i] = to->data[i - 1];
		i--;
	}
	to->data[0] = from->data[0];
	to->size++;
	while (i < from->size - 1)
	{
		from->data[i] = from->data[i + 1];
		i++;
	}
	from->size--;
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->data[0];
	i = 0;
	if (stack->size < 2)
		return ;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->size - 1] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->data[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}
