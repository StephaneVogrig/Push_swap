/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:50:59 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/02 13:40:48 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# define FALSE 0
# define TRUE 1

typedef struct s_gnl_buffer{
	char		data[BUFFER_SIZE];
	ssize_t		i;
}	t_gnl_buffer;

char	*get_next_line(int fd);

#endif
