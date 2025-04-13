/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:55:29 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/13 13:45:44 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "stack.h"

void	sort_three(t_stack *a)
{
	int	f;
	int	s;
	int	t;

	f = a->data[0];
	s = a->data[1];
	t = a->data[2];
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}

void	sort_two(t_stack *a)
{
	if (a->data[0] > a->data[1])
		sa(a);
}

// on cherche l'index du min
int	find_min_index(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	min = stack->data[0];
	index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < min)
		{
			min = stack->data[i];
			index = i;
		}
		i++;
	}
	return (index);
}
/* des qu'on trouve le min on le remonte avec des operations
 ra et rra d4 on le push dans b*/

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	index;

	index = find_min_index(a);
	if (index <= a->size / 2)
	{
		while (index-- > 0)
			ra(a);
	}
	else
	{
		while (index++ < a->size)
			rra(a);
	}
	pb(a, b);
}
