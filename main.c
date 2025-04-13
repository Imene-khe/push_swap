/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:12:44 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/13 14:08:55 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack(argc - 1);
	b = init_stack(argc - 1);
	if (!a || !b)
		return (1);
	parse_args(argc, argv, a);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

