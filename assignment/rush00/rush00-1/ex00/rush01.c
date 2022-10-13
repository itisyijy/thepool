/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:07:08 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/28 14:12:35 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_x_up(int x)
{
	int	tmp;

	tmp = 0;
	while (tmp < x)
	{
		if (tmp == 0)
			ft_putchar('/');
		else if (tmp == x - 1)
			ft_putchar('\\');
		else
			ft_putchar('*');
		tmp++;
	}
}

void	print_x_down(int x)
{
	int	tmp;

	tmp = 0;
	while (tmp < x)
	{
		if (tmp == 0)
			ft_putchar('\\');
		else if (tmp == x - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
		tmp++;
	}
}

void	print_y(int y)
{
	int	tmp;

	tmp = 0;
	while (tmp < y)
	{
		if (tmp == 0 || tmp == y - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
		tmp++;
	}
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0)
			print_x_up(x);
		else if (i == y - 1)
			print_x_down(x);
		else
			print_y(x);
		ft_putchar('\n');
		i++;
	}
}
