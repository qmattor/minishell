/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:29:19 by qmattor           #+#    #+#             */
/*   Updated: 2019/12/21 22:34:14 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_benull(void **arr, size_t size)
{
	int	i;

	i = 0;
	while (size--)
		arr[i++] = NULL;
}
