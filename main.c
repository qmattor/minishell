/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:29:46 by bopok             #+#    #+#             */
/*   Updated: 2021/09/01 16:33:24 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**parsed_args;
	pid_t	new_proc;
	int		status;

	(void)argc;
	(void)argv;
	while (1)
	{
		write(1, "$>", 2);
		get_next_line(1, &input);
		// parsed_args = ft_strsplit(input, ' ');
		for (int i = 0; parsed_args[i]; i++)
			printf("%s\n", parsed_args[i]);
		if (bult_ins(parsed_args, envp))
		{
			parsed_args[0] = clean_call(parsed_args[0]);
			new_proc = fork();
			if (new_proc == 0)	//child process runs the program
				child_proc(parsed_args, envp);
			waitpid(new_proc, &status, 0);
		}
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

char	bult_ins(char **str, char **envp)
{
	pid_t	new_proc;
	int		status;

	if (!ft_strcmp(*str, "cd"))
	{
		write(1, "note: not made yet", 19);
	}
	else if (!ft_strcmp(*str, "ls"))
	{
		new_proc = fork();
		if (new_proc == 0)
			execve("ft_ls", str, envp);
		waitpid(new_proc, &status, 0); 
	}
	else if (!ft_strcmp(*str, "env"))
		while (*envp)
			write(1, *envp, ft_strlen(*envp));
	else
		return 1;
	return 0;
}

void	child_proc(char	**parsed_args, char **envp)
{
	execve(parsed_args[0], (char * const *)&parsed_args[1], envp);// ends child process here
	write(1, "ft_minishell: invalid command: ", 32);
	write(1, parsed_args[0], ft_strlen(parsed_args[0]));
	write(1, "\n", 1);
	exit(0);
}