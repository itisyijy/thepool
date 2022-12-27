/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:49:06 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/08 17:42:52 by jeongyle         ###   ########.fr       */
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
	if (result <= 0)
	{
		*range = NULL;
		return (0);
	}
	tmp = (int *)malloc(sizeof(int) * (result));
	if (tmp == NULL)
		return (-1);
	while (i < result)
	{
		tmp[i] = min + i;
		i++;
	}
	*range = tmp;
	return (result);
}
