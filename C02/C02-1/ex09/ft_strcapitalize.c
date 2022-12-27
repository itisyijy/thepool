/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:45:03 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/31 23:04:31 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	while (!(*str >= 'a' && *str <= 'z') && !(*str >= 'A' && *str <= 'Z'))
		str++;
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 'a' + 'A';
	str++;
	while (*str != '\0')
	{
		if ((*(str - 1) >= 'a' && *(str - 1) <= 'z')
			|| (*(str - 1) >= 'A' && *(str - 1) <= 'Z'))
			if (*str >= 'A' && *str <= 'Z')
				*str = *str + 'a' - 'A';
		if (!(*(str - 1) >= 'a' && *(str - 1) <= 'z')
			&& !(*(str - 1) >= 'A' && *(str - 1) <= 'Z'))
			if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
				if (*str >= 'a' && *str <= 'z')
					*str = *str - 'a' + 'A';
		str++;
	}
	return (ptr);
}
