/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:39:42 by bopok             #+#    #+#             */
/*   Updated: 2021/09/09 12:05:10 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**parse_from_in(char *in)
{
	char	**ret;
	char	*new_in;
	char	not_quotes;
	int		arr[4];

	arr[FIRST] = 0;
	arr[NUMBREAK] = 0;
	new_in = ft_strjoin(in, " ");
	while (new_in[arr[FIRST]])
	{
		if (new_in[arr[FIRST]] == ' ')
			arr[NUMBREAK]++;
		arr[FIRST]++;
	}
	ret = malloc(sizeof(char *) * (arr[NUMBREAK] + 1));
	arr[FIRST] = 0;
	arr[SECOND] = 0;
	arr[ITER] = 0;
	not_quotes = 0;
	while (new_in[arr[FIRST]])
	{
		if (new_in[arr[FIRST]] == '\"')  //ignore escape sequinces for the moment because fuck that
			not_quotes = !not_quotes;
		if (new_in[arr[FIRST]] == ' ' && !not_quotes)
		{
			ret[arr[ITER]++] = ft_strsub(in, arr[SECOND], arr[FIRST] - arr[SECOND]);
			while (new_in[arr[FIRST]] == ' ')
				arr[FIRST]++;
			arr[SECOND] = arr[FIRST];
		}
		else
			arr[FIRST]++;
	}
	ret[arr[ITER]] = NULL;
	free(new_in);
	return (ret);
}

char	*ig_ch(char	*str)
{
	char	*ret_str;
	char	*ptr_new;
	char	*ptr_old;

	ret_str = ft_strnew(ft_strlen(str));
	ptr_new = ret_str;
	ptr_old = str;
	while (*ptr_old)
	{
		if (*ptr_old != '\"')	//idrk what other things should be cleaned atm but they go here
			*ptr_new++ = *ptr_old;
		ptr_old++;
	}
	free(str);
	return (ret_str);
}