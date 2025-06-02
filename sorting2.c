/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:32:28 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/24 14:51:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "stack.h"

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	if (stack->size == 0)
		return (-1);
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

void	reverse_final_sort(t_stack *a)
{
	int	min_index;
	int	i;

	min_index = find_min_index(a);
	i = 0;
	if (min_index <= a->size / 2)
		while (i++ < min_index)
			ra(a);
	else
		while (i++ < a->size - min_index)
			rra(a);
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	max_index;
	int	i;

	while (b->size > 0)
	{
		max_index = find_max_index(b);
		if (max_index <= b->size / 2)
		{
			i = max_index;
			while (i-- > 0)
				rb(b);
		}
		else
		{
			i = b->size - max_index;
			while (i-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	int	nb_chunks;

	if (a->size <= 100)
		nb_chunks = 5;
	else
		nb_chunks = 10;
	normalize(a);
	push_chunks_to_b(a, b, nb_chunks);
	push_back_sorted(a, b);
	reverse_final_sort(a);
}
