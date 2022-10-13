/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:17:25 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/13 19:10:08 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_div2(int a, int b, t_op *operate)
{
	if (b == 0)
		write(1, "Stop : division by zero", 23);
	else
		ft_putnbr((*operate[3])(a, b));
}

void	ft_mod2(int a, int b, t_op *operate)
{
	if (b == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr((*operate[4])(a, b));
}

void	ft_do_op(char **argv, int a, int b)
{
	t_op	operate[5];

	operate[0] = ft_plus;
	operate[1] = ft_minus;
	operate[2] = ft_multiple;
	operate[3] = ft_divide;
	operate[4] = ft_mod;
	if (!ft_strcmp(argv[2], "+"))
		ft_putnbr((*operate[0])(a, b));
	else if (!ft_strcmp(argv[2], "-"))
		ft_putnbr((*operate[1])(a, b));
	else if (!ft_strcmp(argv[2], "*"))
		ft_putnbr((*operate[2])(a, b));
	else if (!ft_strcmp(argv[2], "/"))
		ft_div2(a, b, operate);
	else if (!ft_strcmp(argv[2], "%"))
		ft_mod2(a, b, operate);
	else
		ft_putnbr(0);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;

	if (argc != 4)
		return (1);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	ft_do_op(argv, a, b);
	write(1, "\n", 1);
	return (0);
}
