/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psut_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:28:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:16:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

t_psut_data	unit_test_data_init(char *stack_a, char *stack_b, \
					int nbr_a, int nbr_b)
{
	t_psut_data	data;

	data.stack_a = stack_a;
	data.stack_b = stack_b;
	data.nbr_a = nbr_a;
	data.nbr_b = nbr_b;
	return (data);
}

void	unit_test_data_free(t_psut_data data)
{
	if (data.stack_a)
		free(data.stack_a);
	if (data.stack_b)
		free(data.stack_b);
}
