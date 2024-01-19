/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/18 04:43:43 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack	*stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->nbr = 0;
}

int stack_add(int n, t_stack *stack)
{
	t_i32list	*new;

	new = i32list_new(n);
	if (!new)
		return (ERROR);
	if (!stack->first)
	{
		stack->first = new;
		stack->last = new;
	}
	else
	{
		stack->last->next = new;
		stack->last = new;
	}
	stack->nbr++;
	return (SUCCESS);
}

void	stack_free(t_stack *stack)
{
	if(!stack->first)
		return ;
	i32list_free(&(stack->first));
}
