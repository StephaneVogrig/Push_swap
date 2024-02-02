/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 03:21:39 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/24 22:27:31 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

static void	print_test(char *input, int expected)
{
	int			output;
	t_psstack	stack;
	int			success;

	ps_stack_init(&stack);
	arg_to_stack(input, &stack);
	output = is_sorted(&stack);
	success = output == expected;
	if (!success || VERBOSE)
		ft_printf("input = %20s :\033[32m %i \033[0m", input, expected);
	if (!success)
		ft_printf("|\033[31m %i [KO]\n\033[0m", output);
	else if (VERBOSE)
		ft_printf("|\033[32m %i [OK]\n\033[0m", output);
	if (success)
		unit_test(increase_success);
	ps_stack_free(&stack);
	unit_test(increase_tests);
}

void	is_sorted_tests(void)
{
	unit_test(init);
	print_test("", 1);
	print_test("1", 1);
	print_test("10 20 30 40 50", 1);
	print_test("90 80 30 20 10", 0);
	print_test("5 1", 0);
	print_test("0 1 2 3 4", 1);
	print_test("-10 1 2 3 4", 1);
	print_test("-10 1 2 3 -100", 0);
	unit_test_print_result("is_sorted", 30);
}
