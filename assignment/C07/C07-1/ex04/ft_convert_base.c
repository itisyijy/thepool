/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:55:21 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/08 15:46:56 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_rev_tab(char *tab, int size, int e);

int		convert_int(char *str, char *base, int len);

int	double_check(char *base)
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

int	base_check(char *base)
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
	if (double_check(base) <= 1)
		return (0);
	return (double_check(base));
}

void	ft_putnbr_base(int nbr, char *base, char *result)
{
	int			len;
	long long	n;

	len = base_check(base);
	n = nbr;
	if (len <= 1)
		return ;
	if (nbr < 0)
	{
		*result++ = '-';
		n = n * -1;
	}
	*result = base[n % len];
	if (n >= len)
		ft_putnbr_base(n / len, base, ++result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	len;

	len = base_check(base);
	if (len <= 1)
		return (0);
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13)
		|| *str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	result = convert_int(str, base, len);
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		deci;
	int		count;
	int		e;
	char	*tmp;

	if (base_check(base_from) == 0 || base_check(base_to) == 0)
		return (NULL);
	deci = ft_atoi_base(nbr, base_from);
	tmp = (char *)malloc(sizeof(char) * 31 + 2);
	ft_putnbr_base(deci, base_to, tmp);
	count = 0;
	while (tmp[count] != '\0')
		count++;
	e = -1;
	if (deci < 0)
		e = 0;
	ft_rev_tab(tmp, count, e);
	return (tmp);
}
