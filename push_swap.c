/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:42:37 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/13 14:28:33 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "sorting.h"

void	print_stack(const char *name, t_stack *stack)
{
	int	i = 0;
	printf("%s [size: %d]: ", name, stack->size);
	while (i < stack->size)
		printf("%d ", stack->data[i++]);
	printf("\n");
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		if (a->size == 2)
			sort_two(a);
		else if (a->size == 3)
		{
			print_stack("A avant sort_three", a);
			print_stack("B avant sort_three", b);
			sort_three(a);
		}
		else if (a->size == 4)
			sort_four(a, b);
		else
			sort_five(a, b);
	}
	else
		sort_big_stack(a, b);
}
