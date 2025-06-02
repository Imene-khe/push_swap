/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:12:44 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/24 15:58:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total;

	if (argc < 2)
		return (0);
	total = count_total_numbers(argc, argv);
	a = init_stack(total);
	b = init_stack(total);
	if (!a || !b)
		return (1);
	parse_args(argc, argv, a);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
