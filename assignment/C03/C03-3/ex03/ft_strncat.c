/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:51:24 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/04 10:33:49 by jeongyle         ###   ########.fr       */
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
	while (i_src < nb && src[i_src] != '\0')
		dest[i_dest++] = src[i_src++];
	dest[i_dest] = '\0';
	return (dest);
}
