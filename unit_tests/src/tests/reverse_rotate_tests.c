/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:07:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/22 23:54:18 by svogrig          ###   ########.fr       */
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
	reverse_rotate(&stack);
	output = psut_list_to_str(stack.first, " ");
	if (!output)
		return ;
	success = ft_strcmp(output, expected) == 0;
	if (!success || VERBOSE)
	{
		ft_printf("input = %12s :", input);
		ft_printf("\033[32m %12s \033[0m", expected);
	}
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

void	reverse_rotate_tests(void)
{
	unit_test(init);
	print_test("", "");
	print_test("1", "1");
	print_test("5 1", "1 5");
	print_test("0 1 2 3 4", "4 0 1 2 3");
	unit_test_print_result("reverse rotate", 30);
}
