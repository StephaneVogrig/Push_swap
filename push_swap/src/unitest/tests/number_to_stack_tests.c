/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_stack_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:02:24 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 01:23:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

// test must return NULL
static void	print_test_fail(char *input)
{
	t_psstack	stack;
	char		*output;

	ps_stack_init(&stack);
	output = number_to_stack(input, &stack);
	if (output || VERBOSE)
		ft_printf("input = %10s : \033[32m%10p\033[0m", input, NULL);
	if (output)
		ft_printf(" | \033[31m%10p [KO]\n\033[0m", output);
	else if (VERBOSE)
		ft_printf(" | \033[32m%10p [OK]\n\033[0m", output);
	if (!output)
		unit_test(increase_success);
	unit_test(increase_tests);
}

static void	print_test(char *input, int expected)
{
	t_psstack	stack;
	int			output;
	int			success;

	ps_stack_init(&stack);
	number_to_stack(input, &stack);
	output = stack.first->nbr;
	success = output == expected;
	if (!success || VERBOSE)
		ft_printf("input = %12s : \033[32m%12i\033[0m", input, expected);
	if (!success)
		ft_printf(" | \033[31m%12i[KO]\n\033[0m", output);
	else if (VERBOSE)
		ft_printf(" | \033[32m%12i[OK]\n\033[0m", output);
	if (success)
		unit_test(increase_success);
	ps_stack_free(&stack);
	unit_test(increase_tests);
}

void	number_to_stack_tests(void)
{
	unit_test(init);
	print_test_fail("+ 42");
	print_test_fail("+42+42");
	print_test_fail("42a");
	print_test_fail("a42");
	print_test_fail("a");
	print_test_fail("a  42");
	print_test_fail("-+42");
	print_test_fail("++42");
	print_test("42", 42);
	print_test("42 a", 42);
	print_test("0", 0);
	print_test("-42", -42);
	print_test("+42", 42);
	print_test("-2147483648", -2147483648);
	print_test("2147483647", 2147483647);
	unit_test_print_result("number_to_stack", 30);
}
