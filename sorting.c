/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:08:14 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/25 10:44:17 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sorting.h"

int	has_chunk(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] >= min && a->data[i] <= max)
			return (1);
		i++;
	}
	return (0);
}

static void	handle_chunk_push(t_stack *a, t_stack *b, int min, int chunk_size)
{
	pb(a, b);
	if (b->data[0] < min + chunk_size / 2)
		rb(b);
}

static void	update_chunk_bounds(int *min, int *max, int chunk_size, int total)
{
	*min = *max + 1;
	*max = *min + chunk_size - 1;
	if (*max >= total)
		*max = total - 1;
}

void	push_chunks_to_b(t_stack *a, t_stack *b, int nb_chunks)
{
	int	chunk_size;
	int	total;
	int	min;
	int	max;

	chunk_size = a->size / nb_chunks;
	if (chunk_size < 1)
		chunk_size = 1;
	total = a->size;
	min = 0;
	max = chunk_size - 1;
	while (a->size > 0)
	{
		if (!has_chunk(a, min, max))
		{
			update_chunk_bounds(&min, &max, chunk_size, total);
			continue ;
		}
		if (a->data[0] >= min && a->data[0] <= max)
			handle_chunk_push(a, b, min, chunk_size);
		else
			ra(a);
	}
}

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max;
	int	index;

	max = stack->data[0];
	index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] > max)
		{
			max = stack->data[i];
			index = i;
		}
		i++;
	}
	return (index);
}
