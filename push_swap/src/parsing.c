/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:45:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/15 20:21:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(char *str)
{
	t_int64	n;
	int		sign;

	if (!*str)
		return (ERROR);
	sign = 1;
	while (*str)
	{
		n = 0;
		while (*str == ' ')
			str++;
		if (!*str)
			return (SUCCESS);
		if (*str == '+' || *str == '-')
			sign = 44 - *str++;
		if (!ft_isdigit(*str))
			return (ERROR);
		while (ft_isdigit(*str))
		{
			n = n * 10 + *str - '0';
			if ((sign == 1 && n > INT_MAX) || ( sign == -1 && -n < INT_MIN))
				return (ERROR);
			str++;
		}
		printf("%i\n", (int)(sign * n));
	}
	return (SUCCESS);
}
