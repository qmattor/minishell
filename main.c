/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:29:46 by bopok             #+#    #+#             */
/*   Updated: 2021/08/19 17:43:15 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	*input;
	char	**parsed_args;
	pid_t	new_proc;
	int		status;
	while (1)
	{
		write(1, "$>", 2);
		get_next_line(1, &input);
		parsed_args = ft_strsplit(input, ' ');
		parsed_args[0] = clean_call(parsed_args[0]);
		new_proc = fork();
		if (new_proc == 0)	//child process runs the program
			execve(parsed_args[0], (char * const *)&parsed_args[1], envp);// ends child process here
		waitpid(new_proc, &status, 0);
		
		ft_freetab(parsed_args);
	}
}

char	*clean_call(char *call)
{
	char	*ret;

	if (call[0] == '.' && call[1] == '/')
	{
		ret = ft_strsub(call, 2, ft_strlen(call) - 2);
		free(call);
	}
	else
	{
		ret = ft_strdup(call);
		free(call);
	}
	return (ret);
}
