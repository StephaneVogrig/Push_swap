/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_i_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:07:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/25 04:18:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

static void	print_test(char *input, int ref_nbr, int expected)
{
	int			output;
	t_psstack	stack;
	int			success;

	ps_stack_init(&stack);
	if (!arg_to_stack(input, &stack))
	{
		ft_printf("Memory alloc failed...");
		return ;
	}
	output = compute_i(&stack, ref_nbr);
	success = output == expected;
	if (!success || VERBOSE)
	{
		ft_printf("input = %12s, %2i :", input, ref_nbr);
		ft_printf("\033[32m %2i \033[0m", expected);
	}
	if (!success)
		ft_printf("|\033[31m %2i [KO]\n\033[0m", output);
	else if (VERBOSE)
		ft_printf("|\033[32m %2i [OK]\n\033[0m", output);
	if (success)
		unit_test(increase_success);
	ps_stack_free(&stack);
	unit_test(increase_tests);
}

void	compute_i_tests(void)
{
	unit_test(init);
	print_test("4", 1, 0);
	print_test("4 2", 1, 1);
	print_test("4 0", 1, 2);
	print_test("4 0 2", 1, 2);
	print_test("4 0 1 2", 3, 4);
	print_test("4 1 2 3", 0, 1);
	print_test("2 3 4 1", 0, 3);
	print_test("1 2 3 4", 0, 0);
	print_test("6 1 2 3 4", 5, 5);
	unit_test_print_result("compute_i", 30);
}
