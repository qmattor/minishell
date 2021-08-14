/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 08:04:00 by bopok             #+#    #+#             */
/*   Updated: 2021/08/14 08:22:11 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL
# define FT_MINISHELL
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

extern int	errno;

/*********  	main.c		***********/
char		*parse_args(char *input);

#endif