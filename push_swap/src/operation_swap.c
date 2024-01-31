/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:13:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/31 05:18:57 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	swap(t_psstack *stack)
{
	t_pslist	*temp;

	if (stack->nbr < 2)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	temp->next = stack->first->next;
	stack->first->next = temp;
}

void	sa(t_psstack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_psstack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_psstack *stack_a, t_psstack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
