/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_btoa_deep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:29:47 by stephane          #+#    #+#             */
/*   Updated: 2024/01/31 05:29:52 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	ss_deep(t_psstack *stack_a, t_psstack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rr_deep(t_psstack *stack_a, t_psstack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rrr_deep(t_psstack *stack_a, t_psstack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void	move_do_deep(t_moves *move, t_psstack *stack_a, t_psstack *stack_b)
{
	while (move->sa--)
		swap(stack_a);
	while (move->ra--)
		rotate(stack_a);
	while (move->rra--)
		reverse_rotate(stack_a);
	while (move->sb--)
		swap(stack_b);
	while (move->rb--)
		rotate(stack_b);
	while (move->rrb--)
		reverse_rotate(stack_b);
	while (move->ss--)
		ss_deep(stack_a, stack_b);
	while (move->rr--)
		rr_deep(stack_a, stack_b);
	while (move->rrr--)
		rrr_deep(stack_a, stack_b);
	while (move->pa--)
		push(stack_a, stack_b);
	while (move->pb--)
		push(stack_a, stack_b);
}
void	psut_list_print(t_pslist *list, const char *sep, const char *term)
{
	while (list)
	{
		if (list->next == NULL)
			ft_printf("%i%s", list->nbr, term);
		else
			ft_printf("%i%s", list->nbr, sep);
		list = list->next;
	}
}

t_psstack	stack_dup(t_psstack *stack)
{
	t_psstack	dup;
	t_pslist	*current;

	ps_stack_init(&dup);
	current = stack->first;
	while (current)
	{
		ps_stack_add(current->nbr, &dup);
		current = current->next;
	}
	// psut_list_print(stack->first, " ", "\n");
	// psut_list_print(dup.first, " ", "\n");
	
	return (dup);
}

int	nbr_move_deep(t_psstack *stack_a_deep, t_psstack *stack_b_deep, t_moves	move_deep)
{
	int		deep;
	int		nbr_move_deep;

	deep = 100;
	nbr_move_deep = 0;
	move_do_deep(&move_deep, stack_a_deep, stack_b_deep);
	while (--deep && stack_b_deep->nbr)
	{
		move_deep = best_move_btoa(stack_a_deep, stack_b_deep);
		move_do_deep(&move_deep, stack_a_deep, stack_b_deep);
		nbr_move_deep += move_deep.nbr;
	}
	return (nbr_move_deep);	
}

t_moves	move_btoa_deep_compute(t_psstack *stack_a, t_psstack *stack_b, int pos_in_a, int pos_in_b)
{
	t_moves		move;
	t_psstack	stack_a_deep;
	t_psstack	stack_b_deep;

	stack_a_deep = stack_dup(stack_a);
	stack_b_deep = stack_dup(stack_b);
	move = move_btoa_compute(&stack_a_deep, &stack_b_deep, pos_in_a, pos_in_b);
	move.nbr += nbr_move_deep(&stack_a_deep, &stack_b_deep, move);
	ps_stack_free(&stack_a_deep);
	ps_stack_free(&stack_b_deep);
	return (move);	
}

t_moves	best_move_btoa_deep(t_psstack *stack_a, t_psstack *stack_b)
{
	t_pslist	*current;
	int			i;
	t_moves		move;
	t_moves		best_move;
	int			pos_in_a;

	moves_init(&best_move);
	if (stack_b->nbr == 0)
		return (best_move);
	pos_in_a = position_insert_nbr(stack_a, stack_b->first->nbr);
	best_move = move_btoa_deep_compute(stack_a, stack_b, pos_in_a, 0);
	i = 1;
	current = stack_b->first->next;
	while (current)
	{
		pos_in_a = position_insert_nbr(stack_a, current->nbr);
		move = move_btoa_deep_compute(stack_a, stack_b, pos_in_a, i);
		if (move.nbr < best_move.nbr)
			best_move = move;
		i++;
		current = current->next;
	}
	return (best_move);
}

void	move_btoa_deep(t_psstack *stack_a, t_psstack *stack_b)
{
	t_moves	move;

	while (stack_b->nbr)
	{
		move = best_move_btoa_deep(stack_a, stack_b);
		move_do(&move, stack_a, stack_b);
	}
}