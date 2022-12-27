/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:45:03 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/02 21:40:26 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	while (is_alphanumeric(*str) == 0)
		str++;
	if (is_alphanumeric(*str) == 1)
		*str = *str - 'a' + 'A';
	str++;
	while (*str != '\0')
	{
		if (is_alphanumeric(*(str - 1)) > 0)
		{
			if (is_alphanumeric(*str) == 2)
				*str = *str + 'a' - 'A';
		}
		else
			if (is_alphanumeric(*str) == 1)
					*str = *str - 'a' + 'A';
		str++;
	}
	return (ptr);
}
