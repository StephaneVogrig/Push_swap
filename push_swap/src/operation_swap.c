/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:13:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/02 12:30:22 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	swap(t_psstack *stack)
{
	t_pslist	*temp;

	if (stack->nbr < 2)
		return (SUCCESS);
	temp = stack->first;
	stack->first = stack->first->next;
	temp->next = stack->first->next;
	stack->first->next = temp;
	return (SUCCESS);
}

int	swap_s(t_psstack *stack_a, t_psstack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return (SUCCESS);
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
	swap_s(stack_a, stack_b);
	ft_printf("ss\n");
}
