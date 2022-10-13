/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:43:46 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/02 23:26:41 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	double_check0(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	base_check0(char *base)
{
	char	*tmp;

	tmp = base;
	if (*tmp == '\0' || (*(tmp + 1) == '\0'))
		return (0);
	while (*tmp != '\0')
	{
		if (*tmp == '+' || *tmp == '-'
			|| (*tmp >= 9 && *tmp <= 13) || *tmp == ' ')
			return (0);
		tmp++;
	}
	if (double_check0(base) <= 1)
		return (0);
	return (double_check0(base));
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long long	n;

	len = base_check0(base);
	n = nbr;
	if (len <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n >= len)
		ft_putnbr_base(n / len, base);
	write(1, &base[n % len], 1);
}
