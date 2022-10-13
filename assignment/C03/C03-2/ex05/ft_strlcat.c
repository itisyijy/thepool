/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:13:15 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/03 11:25:01 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i_d;
	unsigned int	i_s;
	unsigned int	cat;

	i_d = 0;
	while (dest[i_d] != '\0')
		i_d++;
	i_s = 0;
	while (src[i_s] != '\0')
		i_s++;
	if (i_d >= size)
		return (i_s + size);
	cat = 0;
	while (cat + i_d + 1 < size && src[cat] != '\0')
	{
		dest[i_d + cat] = src[cat];
		cat++;
	}
	dest[i_d + cat] = '\0';
	return (i_d + i_s);
}
