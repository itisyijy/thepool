/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:50:00 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/31 10:58:36 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_tab(char *tab, int size, int e)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	if (e == 0)
	{
		i = 1;
		j = 1;
	}
	while (i < (size / 2) + j)
	{
		tmp = tab[i];
		tab[i] = tab[size - i + e];
		tab[size - i + e] = tmp;
		i++;
	}
}

int	convert_int(char *str, char *base, int len)
{
	int	result;
	int	digit;

	result = 0;
	while (*str != '\0')
	{
		digit = 0;
		while (base[digit] != '\0')
		{
			if (*str == base[digit])
				result = (result * len) + digit;
			digit++;
		}
		str++;
	}
	return (result);
}
