/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:31:32 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/22 22:49:49 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index(t_pslist *list)
{
	t_pslist	*temp;

	if (stack_src->nbr == 0)
		return ;
	temp = stack_src->first;
	stack_src->first = temp->next;
	temp->next = stack_dest->first;
	stack_dest->first = temp;
}

void	pa(t_psstack *stack_a, t_psstack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_psstack *stack_a, t_psstack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
