/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:58:48 by bopok             #+#    #+#             */
/*   Updated: 2021/08/14 18:42:04 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*newele(int fd)
{
	t_file	*ret;

	ret = malloc(sizeof(t_file));
	ret->index = BUFF_SIZE + 1;
	ret->buf = malloc(BUFF_SIZE);
	ret->fd = fd;
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

	if (file->index >= BUFF_SIZE)	//get new buffer
	{
		file->res = read(file->fd, file->buf, BUFF_SIZE);
		file->index = 0;
		if (file->res <= 0)		//error / eof
			return (NULL);
	}
	i = file->index;
	while (file->index <= BUFF_SIZE)
	{
		if (file->buf[file->index++] == '\n')
		{
			return (ft_strsub(file->buf, i, file->index - i - 1));
		}
	}
	return (ft_strsub(file->buf, i, file->index - i - 1));
}

/*
char	*read_to_newline(t_file *file)
{
	char	*str;
	char	*ptr;

	str = ft_strnew(BUFF_SIZE);
	if (file->index == 0)
		file->res = read(file->fd, file->buf, BUFF_SIZE);
	if (file->res == -1)
	{
		free(str);
		return NULL;
	}
	ptr = &(file->buf[file->index]);					//starts on last '\n'
	while (file->index < file->res)						//problems with the \n lining up with the buffer
		if (file->buf[file->index++] == '\n')
		{
			if (file->index == BUFF_SIZE)
			{
				ft_strncpy(str, ptr, (&file->buf[file->index - 1] - ptr));
				return (str);
			}
			ft_strncpy(str, ptr, (&file->buf[file->index - 1] - ptr));
			file->index += 2;
			return (str);
		}
	ft_strncpy(str, ptr, (&file->buf[file->index] - ptr));
	return (str);
}
*/
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
		if (!fe[fd]->res || fe[fd]->index <= BUFF_SIZE)
		{
			*line = running;
			return (fe[fd]->res);
		}

	}
}

// testing
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	char *line;
	int x = open("test", O_RDONLY);
	int y = open("testtwo", O_RDONLY);
	while (get_next_line(x, &line))
		printf("%s\n", line);
	printf("%s\n", line);
	while (get_next_line(y, &line))
		printf("%s\n", line);
	printf("%s\n", line);
}