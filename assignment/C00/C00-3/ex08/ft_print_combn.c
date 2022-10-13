/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:27:04 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/04 11:55:38 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	set_or_print(int index, int digit, char *comb, int n)
{
	if (index == n)
	{
		write(1, comb, n);
		if (comb[0] != 10 - n + '0')
			write(1, ", ", 2);
	}
	else
	{
		while (digit <= 9)
		{
			comb[index] = digit + '0';
			set_or_print(index + 1, digit + 1, comb, n);
			digit++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	set_or_print(0, 0, comb, n);
}
