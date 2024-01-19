/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:10:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/18 04:52:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_stack *stack_a)//, t_stack *stack_b)
{
	// t_stack	stack_b;
	
	i32list_print(stack_a->first, "\n", "\n");
	// stack_init(&stack_b);
	// stack_free(&stack_b);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		ok;

	if (argc == 1)
		return (0);
	stack_init(&stack);
	ok = args_to_stack(argc, argv, &stack);
	if (ok)
		ok = sort_stack(&stack);
	if (!ok)
		write(2, "Error\n", 6);
	stack_free(&stack);
	return (0);
}
