/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:46:14 by ikhelil           #+#    #+#             */
/*   Updated: 2025/04/13 14:11:42 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_H
# define STACK_H

#include <stdio.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

// Init / utils
t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
void	print_stack(const char *name, t_stack *stack);

// Stack ops
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push_to(t_stack *from, t_stack *to);


// Instructions push_swap
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		if_digit(char c);
int		is_number(const char *str);
int		ft_atoi_secure(const char *str, int *out);
int		has_duplicates(t_stack *stack);
char	**ft_split(char const *s, char c);
void	push_min_to_b(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	normalize(t_stack *stack);
int		parse_args(int argc, char **argv, t_stack *stack);
void	push_swap(t_stack *a, t_stack *b);
void	sort_four(t_stack *a, t_stack *b);



#endif
