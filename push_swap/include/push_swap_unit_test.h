/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_unit_test.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:13:57 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 03:25:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UNIT_TEST_H
# define PUSH_SWAP_UNIT_TEST_H

# include "push_swap.h"

# define VERBOSE 0

typedef struct s_psut_data{
	char	*stack_a;
	char	*stack_b;
	int		nbr_a;
	int		nbr_b;
}	t_psut_data;

void		psut_list_print(t_pslist *list, const char *sep, const char *term);
int			psut_list_index_to_str_len(t_pslist *list, const char *sep);
int			psut_list_to_str_len(t_pslist *list, const char *sep);
char		*psut_list_index_to_str(t_pslist *list, const char *sep);
char		*psut_list_to_str(t_pslist *list, const char *sep);

t_psut_data	unit_test_data_init(char *stack_a, char *stack_b, \
			int nbr_a, int nbr_b);
void		unit_test_data_free(t_psut_data data);

void		ps_list_new_tests(void);
void		psut_list_to_str_tests(void);
void		number_to_stack_tests(void);
void		arg_to_stack_tests(void);
void		swap_head_tests(void);
void		push_tests(void);
void		rotate_tests(void);
void		reverse_rotate_tests(void);
void		ps_index_tests(void);
void		is_sorted_tests(void);

void		si32_to_decstr_offset_tests(void);

#endif