/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:30:36 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/11 11:27:48 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	double_check(char *base)
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

long long	base_check(char *base)
{
	long long		len;
	char			*tmp;

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
	len = double_check(base);
	if (len <= 1)
		return (0);
	return (len);
}
