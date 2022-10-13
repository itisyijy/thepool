/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:55:11 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/31 23:03:12 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char c)
{
	int		digit;
	char	*arr;

	arr = "0123456789abc";
	digit = c / 16;
	write(1, &arr[digit], 1);
	digit = c % 16;
	write(1, &arr[digit], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*u_str;

	u_str = (unsigned int *)str;
	while (*u_str != '\0')
	{
		if (*u_str < 32 || *u_str == 127)
		{
			write(1, "\\", 1);
			print_hex(*u_str);
		}
		else
			write(1, u_str, 1);
		str++;
	}
}
