/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:59:08 by bopok             #+#    #+#             */
/*   Updated: 2021/09/01 10:26:46 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

# define BUFF_SIZE 24
# define NOFLAG 0
# define ENDFILE 1
# define EOL 2

typedef struct			s_file
{
	char				*buf;
	int					index;
	char				res;
	char				flag;
	int					fd;
}						t_file;


t_file					*newele(int fd);
void					delele(t_file *thing);
char					*read_to_newline(t_file *file);
int						get_next_line(const int fd, char **line);
#endif