/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:25:25 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/29 10:25:45 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit(int n)
{
	char	ten;
	char	one;

	ten = '0' + n / 10;
	one = '0' + n % 10;
	write(1, &ten, 1);
	write(1, &one, 1);
}

void	ft_print_comb2(void)
{
	int	left;
	int	right;

	left = 0;
	while (left <= 98)
	{
		right = left + 1;
		while (right <= 99)
		{
			print_digit(left);
			write(1, " ", 1);
			print_digit(right);
			if (left != 98)
				write(1, ", ", 2);
			right++;
		}
		left++;
	}
}
