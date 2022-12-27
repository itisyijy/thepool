/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:21:37 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/08 11:29:16 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*result;

	if (min >= max)
		return (NULL);
	result = (int *)malloc(sizeof(int) * (max - min));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}
