/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:15:45 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/22 21:59:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_psstack *stack)
{
	t_pslist	*temp;

	if (stack->nbr < 2)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	stack->last->next = temp;
	stack->last = temp;
	stack->last->next = NULL;
}

void	ra(t_psstack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_psstack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_psstack *stack_a, t_psstack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
