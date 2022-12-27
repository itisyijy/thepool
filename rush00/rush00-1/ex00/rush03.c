/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyang <joyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:00:16 by joyang            #+#    #+#             */
/*   Updated: 2022/08/28 14:29:35 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_x(int x)
{
	int	tmp;

	tmp = 0;
	while (tmp < x)
	{
		if (tmp == 0)
			ft_putchar('A');
		else if (tmp == x - 1)
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
	int	index;

	index = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (index < y)
	{
		if (index == 0 || index == y - 1)
			print_x(x);
		else
			print_y(x);
		ft_putchar('\n');
		index++;
	}
}
