/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:29:46 by bopok             #+#    #+#             */
/*   Updated: 2021/08/14 08:22:01 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		main(int argc, char **argv)
{
	// char	*input;

	// input = malloc(1024); //string size, basically random number
	// while (1)
	// {
		// printf(">");
		// scanf("%s", input);s
		char **new_argv;
		new_argv = malloc(2);
		*new_argv = "./bash_script";
		*(new_argv + 1) = NULL;
		printf("%i\n", execve("./bash_script", new_argv, NULL));
		printf("%i\n", errno);
	// }
}

char	*parse_args(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		
	}
}
