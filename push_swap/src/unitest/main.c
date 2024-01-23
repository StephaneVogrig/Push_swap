/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:16:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 02:53:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

int	main(void)
{
	si32_to_decstr_offset_tests();
	ps_list_new_tests();
	psut_list_to_str_tests();
	number_to_stack_tests();
	arg_to_stack_tests();
	push_tests();
	reverse_rotate_tests();
	rotate_tests();
	swap_head_tests();
	ps_index_tests();
	return (0);
}
