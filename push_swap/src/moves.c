/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:30:56 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/01 18:50:13 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	moves_init(t_moves *move)
{
	move->sb = 0;
	move->rb = 0;
	move->rrb = 0;
	move->pb = 0;
	move->pa = 0;
	move->sa = 0;
	move->ra = 0;
	move->rra = 0;
	move->ss = 0;
	move->rr = 0;
	move->rrr = 0;
	move->rrr = 0;
	move->nbr = 0;
}

void	moves_reduce_r(t_moves *move)
{
	if (move->ra && move->rb)
	{
		if (move->rra >= move->rrb)
		{
			move->rrr = move->rrb;
			move->rra = move->rra - move->rrb;
			move->rrb = 0;
		}
		else
		{
			move->rrr = move->rra;
			move->rrb = move->rrb - move->rra;
			move->rra = 0;
		}
	}
}

void	moves_reduce_rr(t_moves *move)
{
	if (move->rra && move->rrb)
	{
		if (move->rra >= move->rrb)
		{
			move->rrr = move->rrb;
			move->rra = move->rra - move->rrb;
			move->rrb = 0;
		}
		else
		{
			move->rrr = move->rra;
			move->rrb = move->rrb - move->rra;
			move->rra = 0;
		}
	}
}

void	moves_count(t_moves *move)
{
	move->nbr += move->sa;
	move->nbr += move->sb;
	move->nbr += move->ss;
	move->nbr += move->ra;
	move->nbr += move->rb;
	move->nbr += move->rr;
	move->nbr += move->rra;
	move->nbr += move->rrb;
	move->nbr += move->rrr;
	move->nbr += move->pa;
	move->nbr += move->pb;
}

void	move_do(t_moves *move, t_psstack *stack_a, t_psstack *stack_b)
{
	while (move->rr--)
		rr(stack_a, stack_b);
	while (move->rrr--)
		rrr(stack_a, stack_b);
	while (move->ra--)
		ra(stack_a);
	while (move->rra--)
		rra(stack_a);
	while (move->rb--)
		rb(stack_b);
	while (move->rrb--)
		rrb(stack_b);
	while (move->ss--)
		ss(stack_a, stack_b);
	while (move->sa--)
		sa(stack_a);
	while (move->sb--)
		sb(stack_b);
	while (move->pa--)
		pa(stack_a, stack_b);
	while (move->pb--)
		pb(stack_a, stack_b);
}
