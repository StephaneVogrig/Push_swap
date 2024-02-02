/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:16:22 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/02 12:30:05 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	reverse_rotate(t_psstack *stack)
{
	t_pslist	*prev_last;

	if (stack->nbr < 2)
		return (SUCCESS);
	prev_last = stack->first;
	while (prev_last->next != stack->last)
		prev_last = prev_last->next;
	stack->last->next = stack->first;
	stack->first = stack->last;
	stack->last = prev_last;
	prev_last->next = NULL;
	return (SUCCESS);
}

int	reverse_rotate_r(t_psstack *stack_a, t_psstack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (SUCCESS);
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
	reverse_rotate_r(stack_a, stack_b);
	ft_printf("rrr\n");
}
