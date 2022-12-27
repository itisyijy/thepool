/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:51:39 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/04 18:48:18 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	double_check1(char *base)
{
	long long	i;
	long long	j;

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

int	base_check1(char *base)
{
	int		len;
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
	len = double_check1(base);
	if (len <= 1)
		return (0);
	return (len);
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

	len = base_check1(base);
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
