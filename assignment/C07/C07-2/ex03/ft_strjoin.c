/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:53:58 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/09 20:14:47 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strlen03(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*assign(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src[i];
		dest++;
		i++;
	}
	return (dest);
}

int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < size)
		total = total + strlen03(strs[i++]);
	total = total + strlen03(sep) * (size - 1);
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total;
	char	*str;
	char	*result;

	i = 0;
	if (size == 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		*result = 0;
		return (result);
	}
	total = total_len(size, strs, sep);
	str = (char *)malloc(sizeof(char) * (total + 1));
	result = str;
	i = 0;
	while (i < size)
	{
		str = assign(str, strs[i]);
		if (i != size - 1)
			str = assign(str, sep);
		i++;
	}
	*str = 0;
	return (result);
}
