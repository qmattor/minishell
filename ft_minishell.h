/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 08:04:00 by bopok             #+#    #+#             */
/*   Updated: 2021/09/01 11:42:08 by bopok            ###   ########.fr       */
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
char		*clean_call(char *call);
void		child_proc(char	**parsed_args, char **envp);
char		bult_ins(char **str, char **envp);
char		**parse_from_in(char *in);
#endif