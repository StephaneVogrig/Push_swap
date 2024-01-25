/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:41:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/25 16:31:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "push_swap_list.h"

typedef struct s_psstack{
	t_pslist	*first;
	t_pslist	*last;
	int			nbr;
}	t_psstack;

typedef struct s_moves{
	int	pb;
	int	sb;
	int	rb;
	int	rrb;
	int	pa;
	int	sa;
	int	ra;
	int	rra;
	int	ss;
	int	rr;
	int	rrr;
	int	nbr;
}	t_moves;

int				args_to_stack(int argc, char **argv, t_psstack *stack);
int				arg_to_stack(char *str, t_psstack *stack);
char			*number_to_stack(char *str, t_psstack *stack);

/* stack ---------------------------------------------------------------------*/
void			ps_stack_init(t_psstack	*stack);
int				ps_stack_add(int n, t_psstack *stack);
void			ps_stack_free(t_psstack *stack);

/* opertion push -------------------------------------------------------------*/
void			push(t_psstack *stack_1, t_psstack *stack_2);
void			pa(t_psstack *stack_a, t_psstack *stack_b);
void			pb(t_psstack *stack_a, t_psstack *stack_b);

/* opertion reverse rotate ---------------------------------------------------*/
void			reverse_rotate(t_psstack *stack);
void			rra(t_psstack *stack_a);
void			rrb(t_psstack *stack_b);
void			rrr(t_psstack *stack_a, t_psstack *stack_b);

/* opertion rotate -----------------------------------------------------------*/
void			rotate(t_psstack *stack);
void			ra(t_psstack *stack_a);
void			rb(t_psstack *stack_b);
void			rr(t_psstack *stack_a, t_psstack *stack_b);

/* opertion swap -------------------------------------------------------------*/
void			swap_head(t_psstack *stack);
void			sa(t_psstack *stack_a);
void			sb(t_psstack *stack_b);
void			ss(t_psstack *stack_a, t_psstack *stack_b);

/* push swap index -----------------------------------------------------------*/
void			ps_index(t_pslist *list);

/* push swap sort ------------------------------------------------------------*/
int				is_sorted(t_psstack *stack);
void			ps_sort_2(t_psstack *stack);
void			ps_sort_3(t_psstack *stack);
void			ps_sort_5(t_psstack *stack);
void			ps_sort(t_psstack *stack);

/* moves ---------------------------------------------------------------------*/
void			moves_init(t_moves *move);
void			moves_reduce_r(t_moves *move);
void			moves_reduce_rr(t_moves *move);
void			moves_count(t_moves *move);
void			move_do(t_moves *move, t_psstack *stack_a, t_psstack *stack_b);

/* moves btoa ----------------------------------------------------------------*/
int				compute_i(t_psstack *stack, int ref_nbr);
void			move_btoa(t_psstack *stack_a, t_psstack *stack_b);
void			move_min_to_top(t_psstack *stack);

/* moves btoa ----------------------------------------------------------------*/
t_pslist_pos	position_of_min(t_psstack *stack);
int				position_insert_nbr(t_psstack *stack, int nbr);

#endif
