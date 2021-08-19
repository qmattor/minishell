/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 08:04:00 by bopok             #+#    #+#             */
/*   Updated: 2021/08/17 01:51:38 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL
# define FT_MINISHELL
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line/libft/libft.h"
# include "get_next_line/get_next_line.h"
extern int	errno;

/*********  	main.c		***********/
char	*clean_call(char *call);
#endif