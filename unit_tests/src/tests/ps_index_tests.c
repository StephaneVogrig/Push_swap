/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:22:12 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/26 14:17:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

static void	print_test(char *input, char *expected)
{
	char		*output;
	t_psstack	stack;
	int			success;

	ps_stack_init(&stack);
	arg_to_stack(input, &stack);
	ps_index(stack.first);
	output = psut_list_index_to_str(stack.first, " ");
	if (!output)
		return ;
	success = ft_strcmp(output, expected) == 0;
	if (!success || VERBOSE)
		ft_printf("input = %12s :\033[32m %12s \033[0m", input, expected);
	if (!success)
		ft_printf("|\033[31m %12s [KO]\n\033[0m", output);
	else if (VERBOSE)
		ft_printf("|\033[32m %12s [OK]\n\033[0m", output);
	if (success)
		unit_test(increase_success);
	free(output);
	ps_stack_free(&stack);
	unit_test(increase_tests);
}

void	ps_index_tests(void)
{
	unit_test(init);
	print_test("", "");
	print_test("1", "0");
	print_test("10 20 30 40 50", "0 1 2 3 4");
	print_test("90 80 30 20 10", "4 3 2 1 0");
	print_test("5 1", "1 0");
	print_test("0 1 2 3 4", "0 1 2 3 4");
	print_test("-10 1 2 3 4", "0 1 2 3 4");
	print_test("-10 1 2 3 -100", "1 2 3 4 0");
	unit_test_print_result("rotate", 30);
}
