/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:13:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 05:14:27 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_head(t_stack *stack)
{
	t_i32list	*temp;
	
	if (stack->nbr < 2)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	temp->next = stack->first->next;
	stack->first->next = temp;
}

void	sa(t_stack *stack_a)
{
	swap_head(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap_head(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_head(stack_a);
	swap_head(stack_b);
	ft_printf("ss\n");
}
