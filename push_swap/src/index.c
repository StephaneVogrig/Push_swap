/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:31:32 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/05 00:40:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_index_compute(t_pslist *list, int nbr)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->nbr < nbr)
			i++;
		list = list->next;
	}
	return (i);
}

void	ps_index(t_pslist *list)
{
	t_pslist	*current;

	current = list;
	while (current)
	{
		current->index = ps_index_compute(list, current->nbr);
		current = current->next;
	}
}
