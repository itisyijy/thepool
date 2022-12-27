/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:13:27 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/28 14:12:52 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_x_up(int x)
{
	int	tmp;

	tmp = 0;
	while (tmp < x)
	{
		if (tmp == 0 || tmp == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		tmp++;
	}
}

void	print_x_down(int x)
{
	int	tmp;

	tmp = 0;
	while (tmp < x)
	{
		if (tmp == 0 || tmp == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
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
			ft_putchar('B');
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
