/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:16:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/30 19:18:35 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	is_sorted_tests();
	return (0);
}
