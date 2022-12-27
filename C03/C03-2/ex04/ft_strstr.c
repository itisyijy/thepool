/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:46:04 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/03 13:19:14 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	including(char *str, char *to_find)
{
	char	*ptr;

	ptr = to_find;
	while (*to_find != '\0')
	{
		to_find = ptr;
		while (*str != '\0' && *to_find != '\0' && *str == *to_find)
		{
			str++;
			to_find++;
		}
		if (*to_find == '\0')
			return (1);
		else
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			if (including(str, to_find))
				return (str);
		}
		str++;
	}
	return (0);
}
