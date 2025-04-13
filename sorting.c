/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:08:14 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/13 13:24:58 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	in_chunk(int val, int min, int max)
{
	return (val >= min && val <= max);
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int nb_chunks)
{
	int	size;
	int	chunk;
	int	min;
	int	max;
	int	val;

	size = a->size;
	chunk = size / nb_chunks;
	min = 0;
	max = chunk - 1;
	while (a->size)
	{
		val = a->data[0];
		if (in_chunk(val, min, max))
		{
			pb(a, b);
			if (val < min + (chunk / 2))
				rb(b);
			min++;
			if (min > max)
				max += chunk;
		}
		else
			ra(a);
	}
}

static int	find_max_index(t_stack *b)
{
	int	i;
	int	index;
	int	max;

	i = 0;
	max = b->data[0];
	index = 0;
	while (i < b->size)
	{
		if (b->data[i] > max)
		{
			max = b->data[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	index;

	while (b->size > 0)
	{
		index = find_max_index(b);
		if (index <= b->size / 2)
		{
			while (index-- > 0)
				rb(b);
		}
		else
		{
			while (index++ < b->size)
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
	push_chunk_to_b(a, b, nb_chunks);
	push_back_sorted(a, b);
}

