/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:55:11 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/05 21:41:33 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar0(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*u_str;

	u_str = (unsigned char *)str;
	while (*u_str != '\0')
	{
		if (*u_str < 32 || *u_str >= 127)
		{
			write(1, "\\", 1);
			ft_putchar0("0123456789abcdef"[*u_str / 16]);
			ft_putchar0("0123456789abcdef"[*u_str % 16]);
		}
		else
			ft_putchar0(*u_str);
		u_str++;
	}
}
