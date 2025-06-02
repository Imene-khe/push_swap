/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:40:57 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/20 14:21:08 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "stack.h"

int		parse_args(int argc, char **argv, t_stack *stack);
int		is_number(const char *str);
int		has_duplicates(t_stack *stack);
int		ft_atoi_secure(const char *str, int *out);

#endif