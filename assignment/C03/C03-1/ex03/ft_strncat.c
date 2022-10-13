/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:51:24 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/28 16:12:53 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i_dest;
	unsigned int	i_src;

	i_dest = 0;
	while (dest[i_dest] != '\0')
		i_dest++;
	i_src = 0;
	while (i_src < nb)
		dest[i_dest++] = src[i_src++];
	dest[i_dest] = '\0';
	return (dest);
}
