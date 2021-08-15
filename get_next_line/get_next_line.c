/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:58:48 by bopok             #+#    #+#             */
/*   Updated: 2021/08/15 14:16:11 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*newele(int fd)
{
	t_file	*ret;

	ret = malloc(sizeof(t_file));
	ret->index = BUFF_SIZE + 1;
	ret->buf = ft_strnew(BUFF_SIZE);
	ret->fd = fd;
	ret->flag = 0;
	return (ret);
}

void	delele(t_file *thing)
{
	free(thing->buf);
	free(thing);
}

char	*read_to_newline(t_file *file)
{
	int		i;

	if (file->index >= BUFF_SIZE)
	{
		ft_bzero(file->buf, BUFF_SIZE);
		file->res = read(file->fd, file->buf, BUFF_SIZE);
		file->index = 0;
		if (file->res <= 0)
		{
			file->flag = file->res == 0 ? EOF : 0;
			return (NULL);
		}
	}
	i = file->index;
	while (file->index <= BUFF_SIZE)
	{
		if (file->buf[file->index] == '\n')
		{
			file->flag = EOL;
			file->index++;
			return(ft_strncpy(ft_strnew(file->index - 1 - i), &(file->buf[i]), file->index - 1 - i));
		}
		file->index++;
	}
	return (ft_strncpy(ft_strnew(file->index - i), &(file->buf[i]), file->index - i));
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*fe[OPEN_MAX];
	char			*running;
	char			*temp1;
	char			*temp2;

	running = ft_strnew(1);
	if (fe[fd] == NULL)
		fe[fd] = newele(fd);
	while (1)
	{
		temp1 = running;
		temp2 = read_to_newline(fe[fd]);
		running = ft_strjoin(running, temp2);
		free(temp1);
		free(temp2);
		if (fe[fd]->res == -1)
			return -1;
		if (fe[fd]->flag == EOF)
		{
			*line = running;
			return (0);
		}
		if (fe[fd]->flag == EOL)
		{
			fe[fd]->flag = 0;
			*line = running;
			return (1);
		}
	}
}

// testing
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	char *line;
	int y = open("testTwo", O_RDONLY);
	while (get_next_line(y, &line))
		printf("%s\n", line);
	printf("%s\n", line);
}
