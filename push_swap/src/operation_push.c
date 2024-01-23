/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:15:01 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/22 22:00:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_psstack *stack_dest, t_psstack *stack_src)
{
	t_pslist	*temp;

	if (stack_src->nbr == 0)
		return ;
	temp = stack_src->first;
	stack_src->first = temp->next;
	temp->next = stack_dest->first;
	stack_dest->first = temp;
	stack_dest->nbr++;
	stack_src->nbr--;
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
