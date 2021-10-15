/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:29:46 by bopok             #+#    #+#             */
/*   Updated: 2021/09/05 02:38:18 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"


int		main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**parsed_args;

	(void)argc;
	(void)argv;
	while (1)
	{
		write(1, "$>", 2);
		get_next_line(1, &input);
		if (input[0])					//blank input
		{
			parsed_args = parse_from_in(input);
			if (bult_ins(parsed_args, envp))	//checks for input
				child_proc(parsed_args, envp);
			ft_freetab(parsed_args);
		}
	}
}

char	*clean_call(char *call)
{
	char	*ret;
	char	*ptr1;
	char	*ptr2;

	ret = ft_strnew(ft_strlen(call) - 2);
	ptr1 = call + 2;
	ptr2 = ret;
	while (*ptr1)
	{
		*ptr2++ = *ptr1;
		ptr1++;
	}
	free(call);
	return (ret);
}

char	bult_ins(char **str, char **envp)
{
	pid_t	new_proc;
	int		status;


	if (!ft_strcmp(*str, "cd"))
	{
		//this is very broken and I don't know why
		chdir(str[1]);
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
		{
			write(1, *envp, ft_strlen(*envp));
			write(1, "\n", 1);
			envp++;
		}
	else if (!ft_strcmp(*str, "echo"))
	{
		status = 1;						//just reusing a var, ignore name
		while (str[status])
		{
			str[status] = ig_ch(str[status]);
			write(1, str[status], ft_strlen(str[status]));	
			write(1, " ", 1);
			status++;
		}
		write(1, "\n", 1);
	}
	else if (!ft_strcmp(*str, "exit"))
	{
		exit(0);
	}
	else
		return 1;
	return 0;
}

void	child_proc(char	**parsed_args, char **envp)
{
	char	*og_call;
	pid_t	new_proc;
	int		status;

	og_call = ft_strdup(parsed_args[0]);
	parsed_args[0] = clean_call(parsed_args[0]);
	new_proc = fork();
	if (new_proc == 0)	//child process runs the program
	{
		execve(parsed_args[0], (char * const *)&parsed_args[1], envp);// ends child process here
		write(1, "ft_minishell: invalid command: ", 32);
		write(1, og_call, ft_strlen(og_call));
		write(1, "\n", 1);
		exit(0);
	}
	waitpid(new_proc, &status, 0);	
}