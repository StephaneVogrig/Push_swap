/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si32_to_decstr_offset_tests.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:47:34 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:16:58 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

static void	print_test(int n, char *expected)
{
	char	output[12];

	ft_bzero(output, 12);
	si32_to_decstr_offset(output, n);
	if (ft_strcmp(output, expected) == 0)
	{
		unit_test(increase_success);
		if (VERBOSE)
		{
			ft_printf("input = %12i : \033[32m%12s\033[0m", n, expected);
			ft_printf(" | \033[32m%12s [OK]\n\033[0m", output);
		}
	}
	else
	{
		ft_printf("input = %12i : \033[32m%12s\033[0m", n, expected);
		ft_printf(" | \033[31m%12s [KO]\n\033[0m", output);
	}
	unit_test(increase_tests);
}

void	si32_to_decstr_offset_tests(void)
{
	unit_test(init);
	print_test(0, "0");
	print_test(42, "42");
	print_test(-42, "-42");
	print_test(-2147483648, "-2147483648");
	print_test(2147483647, "2147483647");
	unit_test_print_result("si32_add_decstr_tests", 30);
}
