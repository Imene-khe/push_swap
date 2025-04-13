/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:35:02 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/12 22:57:20 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	push_to(b, a);
	write(1, "pa\n", 3);
}
