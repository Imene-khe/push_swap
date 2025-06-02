/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:45:20 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/24 09:44:49 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

static int	*copy_stack_to_array(t_stack *stack)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		arr[i] = stack->data[i];
		i++;
	}
	return (arr);
}

static void	indexify_stack(t_stack *stack, int *sorted)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->data[i] == sorted[j])
			{
				stack->data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	normalize(t_stack *stack)
{
	int	*sorted;

	sorted = copy_stack_to_array(stack);
	if (!sorted)
		return ;
	sort_array(sorted, stack->size);
	indexify_stack(stack, sorted);
	free(sorted);
}
