/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:41:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 13:32:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "i32list.h"

typedef struct	s_stack {
	t_i32list	*first;
	t_i32list	*last;
	int			nbr;
}	t_stack;

int		args_to_stack(int argc, char **argv, t_stack *stack);
int		arg_to_stack(char *str, t_stack *stack);
char	*number_to_stack(char *str, t_stack *stack);

/* stack ---------------------------------------------------------------------*/
void	stack_init(t_stack	*stack);
int 	stack_add(int n, t_stack *stack);
void	stack_free(t_stack *stack);

/* opertion push -------------------------------------------------------------*/
void	push(t_stack *stack_1, t_stack *stack_2);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

/* opertion reverse rotate ---------------------------------------------------*/
void	push(t_stack *stack_1, t_stack *stack_2);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

/* opertion rotate -----------------------------------------------------------*/
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

/* opertion swap -------------------------------------------------------------*/
void	swap_head(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

#endif
