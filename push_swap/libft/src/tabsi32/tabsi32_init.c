/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabsi32_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:32:35 by stephane          #+#    #+#             */
/*   Updated: 2024/02/01 17:01:29 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

t_tabsi32	tabsi32_init(int *tab, int size)
{
	t_tabsi32	new;

	new.elem = tab;
	new.size = size;
	return (new);
}
