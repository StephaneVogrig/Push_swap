/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:16:22 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:15:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_psstack *stack)
{
	t_pslist	*prev_last;

	if (stack->nbr < 2)
		return ;
	prev_last = stack->first;
	while (prev_last->next != stack->last)
		prev_last = prev_last->next;
	stack->last->next = stack->first;
	stack->first = stack->last;
	stack->last = prev_last;
	prev_last->next = NULL;
}

void	rra(t_psstack *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_psstack *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_psstack *stack_a, t_psstack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
