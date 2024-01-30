/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:26:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/30 17:03:58 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

t_pslist_pos	position_of_min(t_psstack *stack)
{
	t_pslist		*current;
	int				i;
	t_pslist_pos	min;
	int				min_nbr;

	if (!stack->first)
		return (pslist_pos_init());
	min.i = 0;
	min.ptr = stack->first;
	min_nbr = stack->first->nbr;
	i = 0;
	current = stack->first->next;
	while (current)
	{
		i++;
		if ( current->nbr < min_nbr)
		{
			min.i = i;
			min.ptr = current;
			min_nbr = current->nbr;
		}
		current = current->next;
	}
	return (min);
}

int	position_insert_nbr(t_psstack *stack, int nbr)
{
	t_pslist		*current;
	t_pslist_pos	min;
	int				i;

	min = position_of_min(stack);
	i = 0;
	current = stack->first;
	while (i < min.i && nbr > current->nbr)
	{		
		i++;
		current = current->next;
	}
	if (i > 0)
		return (i);
	current = min.ptr;
	i = min.i;
	while (current && nbr > current->nbr)
	{
		i++;
		current = current->next;
	}
	// if (i == stack->nbr)
	// 	i = 0;
	return (i);
}
