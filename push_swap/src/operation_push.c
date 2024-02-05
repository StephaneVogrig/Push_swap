/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:15:01 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/05 00:38:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_psstack *stack_dest, t_psstack *stack_src)
{
	t_pslist	*temp;

	if (stack_src->nbr == 0)
		return (SUCCESS);
	temp = stack_src->first;
	stack_src->first = temp->next;
	temp->next = stack_dest->first;
	stack_dest->first = temp;
	if (stack_dest->nbr == 0)
		stack_dest->last = temp;
	stack_dest->nbr++;
	stack_src->nbr--;
	if (stack_src->nbr == 0)
		stack_src->last = NULL;
	return (SUCCESS);
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
