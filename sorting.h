/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:44:25 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/25 10:44:27 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include <stdio.h>
# include "stack.h"

void	push_back_sorted(t_stack *a, t_stack *b);
void	sort_big_stack(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
int		ind_max_index(t_stack *stack);

#endif
