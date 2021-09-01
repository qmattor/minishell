/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:39:42 by bopok             #+#    #+#             */
/*   Updated: 2021/09/01 16:36:13 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**parse_from_in(char *in)
{
	char	**ret;
	char	not_quotes;
	int		first;
	int		second;
	int		i;
	int		num_breaks;

	first = 0;
	num_breaks = 0;
	while (in[first])
	{
		if (in[first] == ' ')		//bc it's for malloc idc that it will over count
			num_breaks++;
		first++;
	}
	ret = malloc(sizeof(char *) * num_breaks);
	first = 0;
	second = 0;
	i = 0;
	not_quotes = 0;
	while (in[first])
	{
		if (in[first] == '\"')  //ignore escape sequinces for the moment because fuck that
			not_quotes = !not_quotes;
		if (in[first] == ' ' && !not_quotes)
		{
			ret[i++] = ft_strsub(in, second, first - second);
			while (in[first] == ' ')
				first++;
			second = first;
		}
	}
	ret[i] = NULL;
}