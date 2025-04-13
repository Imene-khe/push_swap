#ifndef SORTING_H
# define SORTING_H

# include <stdio.h>
# include "stack.h"

void	push_chunk_to_b(t_stack *a, t_stack *b, int nb_chunks);
void	push_back_sorted(t_stack *a, t_stack *b);
void	sort_big_stack(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

#endif
