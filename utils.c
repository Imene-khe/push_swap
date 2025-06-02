/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelil <ikhelil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:20:57 by ikhelil           #+#    #+#             */
/*   Updated: 2025/05/25 11:01:26 by ikhelil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	if_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!if_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_secure(const char *str, int *out)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (0);
		str++;
	}
	*out = (int)(res * sign);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->data[i] == stack->data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
