/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:30:28 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/10 14:33:35 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	double_check(char *base);
int			base_check(char *base);

void	ft_putnbr_base(int nbr, char *base, char *tmp)
{
	int			len;
	long long	n;

	len = base_check(base);
	n = nbr;
	if (len <= 1)
		return ;
	if (nbr < 0)
		n = n * -1;
	if (n >= len)
		ft_putnbr_base(n / len, base, tmp - 1);
	*tmp = base[n % len];
}

long long	convert_int(char *str, char *base, long long len)
{
	long long	result;
	long long	digit;

	result = 0;
	while (*str != '\0')
	{
		digit = 0;
		while (*str != base[digit] && base[digit])
			digit++;
		if (base[digit] == '\0')
			return (result);
		else
			result = (result * len) + digit;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	result;
	long long	sign;
	long long	len;

	len = base_check(base);
	if (len <= 1)
		return (0);
	sign = 1;
	while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	result = convert_int(str, base, len);
	return (result * sign);
}

int	malloc_size(int deci, char *base_to)
{
	int	base;
	int	size;
	int	tmp;

	base = 0;
	size = 0;
	tmp = deci;
	while (base_to[base] != '\0')
		base++;
	if (deci == -2147483648)
		return (11);
	else if (tmp < 0)
		tmp = tmp * -1;
	while (tmp > 0)
	{
		tmp = tmp / base;
		size++;
	}
	if (deci <= 0)
		return (size + 1);
	return (size);
}

char	*ft_convert_base(char *str, char *base_from, char *base_to)
{
	int		len;
	int		deci;
	char	*tmp;

	if (base_check(base_from) == 0 || base_check(base_to) == 0)
		return (NULL);
	deci = ft_atoi_base(str, base_from);
	if (deci < 0)
		len = malloc_size(deci, base_to) + 1;
	else
		len = malloc_size(deci, base_to);
	tmp = (char *)malloc(sizeof(char) * len);
	if (deci < 0)
		tmp[0] = '-';
	ft_putnbr_base(deci, base_to, &tmp[len - 2]);
	tmp[len - 1] = '\0';
	return (tmp);
}
