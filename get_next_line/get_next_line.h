/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:59:08 by bopok             #+#    #+#             */
/*   Updated: 2021/08/15 00:53:07 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

# define BUFF_SIZE 24

typedef struct			s_file
{
	char				*buf;
	int					index;
	char				res;
	int					fd;
}						t_file;

#endif