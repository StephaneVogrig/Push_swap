/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:06:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 01:02:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

static void	print_test_2(t_psut_data input, t_psut_data expected, \
			t_psut_data output)
{
	int	success;

	success = ft_strcmp(output.stack_a, expected.stack_a) == 0;
	success *= ft_strcmp(output.stack_b, expected.stack_b) == 0;
	success *= output.nbr_a == expected.nbr_a && output.nbr_a == expected.nbr_a;
	if (VERBOSE || !success)
	{
		ft_printf("input = %12s (%i) : ", input.stack_a, input.nbr_a);
		ft_printf("%12s (%i) | ", input.stack_b, input.nbr_b);
		ft_printf("\033[32m %12s (%i) : ", expected.stack_a, expected.nbr_a);
		ft_printf("%12s(%i)\033[0m |", expected.stack_b, expected.nbr_b);
	}
	if (!success)
	{
		ft_printf("\033[31m %12s (%i) : ", output.stack_a, output.nbr_a);
		ft_printf("%12s (%i) [KO]\n\033[0m", output.stack_b, output.nbr_b);
	}
	else if (VERBOSE)
	{
		ft_printf("\033[32m %12s (%i) : ", output.stack_a, output.nbr_a);
		ft_printf("%12s (%i) [OK]\n\033[0m", output.stack_b, output.nbr_b);
	}
	if (success)
		unit_test(increase_success);
	unit_test(increase_tests);
}

static void	print_test(t_psut_data input, t_psut_data expected)
{
	t_psut_data	output;
	t_psstack	stack_dest;
	t_psstack	stack_src;

	output = unit_test_data_init(NULL, NULL, 0, 0);
	ps_stack_init(&stack_dest);
	ps_stack_init(&stack_src);
	arg_to_stack(input.stack_a, &stack_dest);
	arg_to_stack(input.stack_b, &stack_src);
	push(&stack_dest, &stack_src);
	output.stack_a = psut_list_to_str(stack_dest.first, " ");
	output.stack_b = psut_list_to_str(stack_src.first, " ");
	output.nbr_a = stack_dest.nbr;
	output.nbr_b = stack_src.nbr;
	if (output.stack_a && output.stack_b)
		print_test_2(input, expected, output);
	unit_test_data_free(output);
	ps_stack_free(&stack_dest);
	ps_stack_free(&stack_src);
}

void	push_tests_2(void)
{
	t_psut_data	input;
	t_psut_data	expected;

	input = unit_test_data_init("-8 -9", "-1 -2", 2, 2);
	expected = unit_test_data_init("-1 -8 -9", "-2", 3, 1);
	print_test(input, expected);
}

void	push_tests(void)
{
	t_psut_data	input;
	t_psut_data	expected;

	unit_test(init);
	input = unit_test_data_init("", "", 0, 0);
	expected = unit_test_data_init("", "", 0, 0);
	print_test(input, expected);
	input = unit_test_data_init("", "1", 0, 1);
	expected = unit_test_data_init("1", "", 1, 0);
	print_test(input, expected);
	input = unit_test_data_init("", "1 2", 0, 2);
	expected = unit_test_data_init("1", "2", 1, 1);
	print_test(input, expected);
	input = unit_test_data_init("2 3", "1", 2, 1);
	expected = unit_test_data_init("1 2 3", "", 3, 0);
	print_test(input, expected);
	input = unit_test_data_init("8 9", "1 2", 2, 2);
	expected = unit_test_data_init("1 8 9", "2", 3, 1);
	print_test(input, expected);
	input = unit_test_data_init("7 8 9", "1 2 3 4 5 6", 3, 6);
	expected = unit_test_data_init("1 7 8 9", "2 3 4 5 6", 4, 5);
	print_test(input, expected);
	push_tests_2();
	unit_test_print_result("push", 30);
}
