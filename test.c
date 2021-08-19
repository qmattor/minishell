/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopok <bopok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 00:50:41 by bopok             #+#    #+#             */
/*   Updated: 2021/08/19 02:10:36 by bopok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv, char **envp)
{
	char	**args = {"-l", "-a", NULL};
	execve("test3.out", NULL, envp);
	write(1, "failed\n", 7);
}