/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:45:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 04:36:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*number_to_stack(char *str, t_stack *stack)
{
	t_si64	n;
	int		sign;
	
	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		sign = 44 - *str++;
	if (!ft_isdigit(*str))
		return (NULL);
	while (ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		if ((sign == 1 && n > INT_MAX) || ( sign == -1 && -n < INT_MIN))
			return (NULL);
		str++;
	}
	if (*str && *str != ' ')
		return (NULL);
	n *= sign;
	if(is_in_i32list(n, stack->first))
		return (NULL);
	if (stack_add(n, stack) == ERROR)
		return (NULL);
	return (str);
}

int	arg_to_stack(char *str, t_stack *stack)
{
	int	number_in_arg;

	if (*str == '\0')
		return (ERROR);
	number_in_arg = FALSE;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '\0')
			break ;
		str = number_to_stack(str, stack);
		if (str == NULL)
			return (ERROR);
		number_in_arg = TRUE;
	}
	return (number_in_arg == TRUE);
}

int	args_to_stack(int argc, char **argv, t_stack *stack)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (arg_to_stack(argv[i++], stack) == ERROR)
			return (ERROR); 
	}
	return (SUCCESS);
}
