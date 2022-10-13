/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:34:46 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/28 16:12:29 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i_dest;
	int	i_src;

	i_dest = 0;
	while (dest[i_dest] != '\0')
		i_dest++;
	i_src = 0;
	while (src[i_src] != '\0')
		dest[i_dest++] = src[i_src++];
	dest[i_dest] = '\0';
	return (dest);
}
