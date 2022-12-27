/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:49:06 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/08 22:24:15 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	result;
	int	*tmp;

	i = 0;
	result = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tmp = (int *)malloc(sizeof(int) * (result));
	if (tmp == NULL)
		return (-1);
	while (min + i < max)
	{
		tmp[i] = min + i;
		i++;
	}
	*range = tmp;
	return (result);
}
