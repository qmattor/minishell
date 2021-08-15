/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:29:46 by bopok             #+#    #+#             */
/*   Updated: 2021/08/14 10:00:34 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		main(int argc, char **argv, char **envp)
{
	
	/*
	char **new_argv;
	new_argv = malloc(2);
	*new_argv = "./bash_script";
	*(new_argv + 1) = NULL;
	printf("%i\n", execve("./bash_script", new_argv, envp));
	printf("%i\n", errno);
	*/
}

char	*scrape_args(char *input)
{
	int		i;
	char	*path;
	char	**attr;

	i = -1;
	while (input[i++])
	{
		if (input[i] == ' ' || !input[i])
		{
			path = ft_strnew(i + 1);
			ft_strncpy(path, input, i);
			break ;
		}
	}
	attr = ft_strsplit(&(input[i]), ' ');
}
