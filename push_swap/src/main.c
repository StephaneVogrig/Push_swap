/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:10:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:19:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_unit_test.h"

int	sort_ps_stack(t_psstack *stack_a)
{
	psut_list_print(stack_a->first, "\n", "\n");
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_psstack	stack;
	int			ok;

	if (argc == 1)
		return (0);
	ps_stack_init(&stack);
	ok = args_to_stack(argc, argv, &stack);
	if (ok)
		ok = sort_ps_stack(&stack);
	if (!ok)
		write(2, "Error\n", 6);
	ps_stack_free(&stack);
	return (0);
}
