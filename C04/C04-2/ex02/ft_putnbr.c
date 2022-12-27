/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:19:50 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/28 22:20:06 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_int(int nb, long long digit)
{
	char	c;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (digit / 10 > 0)
	{
		digit = digit / 10;
		c = '0' + (nb / digit);
		write(1, &c, 1);
		nb = nb % digit;
	}
}

void	ft_putnbr(int nb)
{
	int			tmp;
	long long	digit;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	tmp = nb;
	digit = 1;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		digit = digit * 10;
	}
	print_int(nb, digit);
}
