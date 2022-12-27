/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:20:51 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/02 22:34:14 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_size(int size)
{
	char	c;

	if (size > 9)
		print_size(size / 10);
	c = size % 10;
	write(1, &c, 1);
}

void	print_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (*(par[i].str) != 0)
	{
		print_size(par[i].size);
		print_str(par[i].str);
		print_str(par[i].copy);
		i++;
	}
}
