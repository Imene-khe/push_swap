/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:55:29 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/24 14:57:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "stack.h"
#include "sorting.h"

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

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	index;
	int	i;

	index = find_min_index(a);
	if (index <= a->size / 2)
	{
		i = index;
		while (i-- > 0)
			ra(a);
	}
	else
	{
		i = a->size - index;
		while (i-- > 0)
			rra(a);
	}
	pb(a, b);
}
