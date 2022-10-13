/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:53:58 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/08 15:06:00 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (len);
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total;
	int		i;
	char	*str;
	char	*result;

	i = 0;
	total = 0;
	while (i < size)
		total = total + ft_strlen(strs[i++]);
	total = total + (ft_strlen(sep) * (size - 1));
	str = (char *)malloc(sizeof(char) * total + 1);
	result = str;
	i = 0;
	while (i < size)
	{
		str = assign(str, strs[i]);
		if (i != size - 1)
			str = assign(str, sep);
		i++;
	}
	*str = '\0';
	return (result);
}
