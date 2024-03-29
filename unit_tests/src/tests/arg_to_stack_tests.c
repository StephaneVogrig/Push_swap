/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_stack_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:58:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:16:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

static void	print_test_2(char *input, int expected_ret, char *expected_stack)
{
	ft_printf("input = %12s :", input);
	ft_printf("\033[32m %i, %12s \033[0m", expected_ret, expected_stack);
}

static void	print_test(char *input, int expected_ret, char *expected_stack)
{
	char		*output_stack;
	int			output_ret;
	t_psstack	stack;
	int			success;

	ps_stack_init(&stack);
	output_ret = arg_to_stack(input, &stack);
	output_stack = psut_list_to_str(stack.first, " ");
	if (!output_stack)
		return ;
	success = ft_strcmp(output_stack, expected_stack) == 0;
	success *= output_ret == expected_ret;
	if (!success || VERBOSE)
		print_test_2(input, expected_ret, expected_stack);
	if (!success)
		ft_printf("|\033[31m %i, %12s [KO]\n\033[0m", output_ret, output_stack);
	else if (VERBOSE)
		ft_printf("|\033[32m %i, %12s [OK]\n\033[0m", output_ret, output_stack);
	if (success)
		unit_test(increase_success);
	free(output_stack);
	ps_stack_free(&stack);
	unit_test(increase_tests);
}

void	arg_to_stack_tests(void)
{
	unit_test(init);
	print_test("0", TRUE, "0");
	print_test("42 0", TRUE, "42 0");
	print_test("42 0 2", TRUE, "42 0 2");
	print_test("42 0 -42", TRUE, "42 0 -42");
	print_test("42 0 42", FALSE, "42 0");
	print_test("-2147483648", TRUE, "-2147483648");
	print_test("2147483647", TRUE, "2147483647");
	print_test("2147483647 -2147483648", TRUE, "2147483647 -2147483648");
	print_test("2147483648", FALSE, "");
	print_test("-2147483649", FALSE, "");
	print_test("1 9 6 5 -9 -4 3", TRUE, "1 9 6 5 -9 -4 3");
	unit_test_print_result("arg_to_stack", 30);
}
