/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 03:17:39 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 03:18:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_psstack *stack)
{
	int			nbr;
	t_pslist	*current;

	if (stack->nbr < 2)
		return (TRUE);
	nbr = stack->first->nbr;
	current = stack->first->next;
	while (current)
	{
		if (current->nbr < nbr)
			return (FALSE);
		nbr = current->nbr;
		current = current->next;
	}
	return (TRUE);
}
