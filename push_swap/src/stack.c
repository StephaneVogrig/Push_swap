/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/01 17:11:19 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	ps_stack_init(t_psstack	*stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->nbr = 0;
}

int	ps_stack_add(int n, t_psstack *stack)
{
	t_pslist	*new;

	new = ps_list_new(n);
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

void	ps_stack_free(t_psstack *stack)
{
	if (!stack->first)
		return ;
	ps_list_free(&(stack->first));
}

void	ps_stack_to_array(t_psstack *stack, int *x)
{
	t_pslist	*current;

	current = stack->first;
	while (current)
	{
		*x++ = current->nbr;
		current = current->next;
	}
}
