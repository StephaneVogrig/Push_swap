/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:56:21 by stephane          #+#    #+#             */
/*   Updated: 2024/02/05 00:36:05 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_operation(char *op, t_psstack *stack_a, t_psstack *stack_b)
{
	if (ft_strcmp(op, "rr\n") == 0)
		return (rotate_r(stack_a, stack_b));
	if (ft_strcmp(op, "rrr\n") == 0)
		return (reverse_rotate_r(stack_a, stack_b));
	if (ft_strcmp(op, "ra\n") == 0)
		return (rotate(stack_a));
	if (ft_strcmp(op, "rb\n") == 0)
		return (rotate(stack_b));
	if (ft_strcmp(op, "rra\n") == 0)
		return (reverse_rotate(stack_a));
	if (ft_strcmp(op, "rrb\n") == 0)
		return (reverse_rotate(stack_b));
	if (ft_strcmp(op, "ss\n") == 0)
		return (swap_s(stack_a, stack_b));
	if (ft_strcmp(op, "sa\n") == 0)
		return (swap(stack_a));
	if (ft_strcmp(op, "sb\n") == 0)
		return (swap(stack_b));
	if (ft_strcmp(op, "pa\n") == 0)
		return (push(stack_a, stack_b));
	if (ft_strcmp(op, "pb\n") == 0)
		return (push(stack_b, stack_a));
	return (ERROR);
}

int	run_checker(t_psstack *stack_a, t_psstack *stack_b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (do_operation(operation, stack_a, stack_b) == ERROR)
			return (ERROR);
		free(operation);
		operation = get_next_line(0);
	}
	if (stack_b->nbr == 0 && is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_psstack	stack_a;
	t_psstack	stack_b;
	int			ok;

	if (argc == 1)
		return (0);
	ps_stack_init(&stack_a);
	ps_stack_init(&stack_b);
	ok = args_to_stack(argc, argv, &stack_a);
	if (ok)
		ok = run_checker(&stack_a, &stack_b);
	if (!ok)
		write(2, "Error\n", 6);
	ps_stack_free(&stack_a);
	ps_stack_free(&stack_b);
	return (0);
}
