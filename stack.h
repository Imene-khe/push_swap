/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:46:14 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/25 10:53:47 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

// basics de mes piles
t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
void	exit_error(void);

// les op internes
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push_to(t_stack *from, t_stack *to);

// les instructions de base
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

// pour le parsing
int		if_digit(char c);
int		is_number(const char *str);
int		ft_atoi_secure(const char *str, int *out);
int		has_duplicates(t_stack *stack);
char	**ft_split(const char *s, char c);
int		count_total_numbers(int argc, char **argv);
void	parse_args(int argc, char **argv, t_stack *stack);

// pour le tri
void	push_swap(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	push_min_to_b(t_stack *a, t_stack *b);
void	normalize(t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
void	reverse_final_sort(t_stack *a);
int		has_chunk(t_stack *a, int min, int max);
void	push_chunks_to_b(t_stack *a, t_stack *b, int nb_chunks);

#endif
