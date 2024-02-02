/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:41:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/02 12:34:55 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	int	sb;
	int	rb;
	int	rrb;
	int	sa;
	int	ra;
	int	rra;
	int	ss;
	int	rr;
	int	rrr;
	int	pa;
	int	pb;
	int	nbr;
}	t_moves;

int				args_to_stack(int argc, char **argv, t_psstack *stack);
int				arg_to_stack(char *str, t_psstack *stack);
char			*number_to_stack(char *str, t_psstack *stack);

/* stack ---------------------------------------------------------------------*/
void			ps_stack_init(t_psstack	*stack);
int				ps_stack_add(int n, t_psstack *stack);
void			ps_stack_free(t_psstack *stack);
void			ps_stack_to_array(t_psstack *stack, int *x);

/* opertion push -------------------------------------------------------------*/
int				push(t_psstack *stack_1, t_psstack *stack_2);
void			pa(t_psstack *stack_a, t_psstack *stack_b);
void			pb(t_psstack *stack_a, t_psstack *stack_b);

/* opertion reverse rotate ---------------------------------------------------*/
int				reverse_rotate(t_psstack *stack);
int				reverse_rotate_r(t_psstack *stack_a, t_psstack *stack_b);
void			rra(t_psstack *stack_a);
void			rrb(t_psstack *stack_b);
void			rrr(t_psstack *stack_a, t_psstack *stack_b);

/* opertion rotate -----------------------------------------------------------*/
int				rotate(t_psstack *stack);
int				rotate_r(t_psstack *stack_a, t_psstack *stack_b);
void			ra(t_psstack *stack_a);
void			rb(t_psstack *stack_b);
void			rr(t_psstack *stack_a, t_psstack *stack_b);

/* opertion swap -------------------------------------------------------------*/
int				swap(t_psstack *stack);
int				swap_s(t_psstack *stack_a, t_psstack *stack_b);
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

/* lis -----------------------------------------------------------------------*/
int				lis(t_psstack *stack);

/* moves ---------------------------------------------------------------------*/
void			moves_init(t_moves *move);
void			moves_reduce_r(t_moves *move);
void			moves_reduce_rr(t_moves *move);
void			moves_count(t_moves *move);
void			move_do(t_moves *move, t_psstack *stack_a, t_psstack *stack_b);

/* moves build ---------------------------------------------------------------*/
t_moves			move_build_ra_rb(int ra, int rb);
t_moves 		move_build_rra_rrb(int rra, int rrb);
t_moves 		move_build_ra_rrb(int ra, int rrb);
t_moves 		move_build_rb_rra(int rb, int rra);

/* moves btoa ----------------------------------------------------------------*/
void			move_btoa(t_psstack *stack_a, t_psstack *stack_b);
void			move_min_to_top(t_psstack *stack);

/* moves atob ----------------------------------------------------------------*/
void			move_atob(t_psstack *stack_a, t_psstack *stack_b);

/* moves btoa ----------------------------------------------------------------*/
t_pslist_pos	position_of_min(t_psstack *stack);
int				position_insert_nbr(t_psstack *stack, int nbr);

#endif
