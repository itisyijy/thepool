/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:54:58 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/13 15:38:17 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	skip_same(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 2 && (*f)(tab[i], tab[i + 1]) == 0)
		i++;
	return (i);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (tab == 0)
		return (1);
	i = skip_same(tab, length, f);
	if ((*f)(tab[i], tab[i + 1]) >= 0)
	{
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) < 0)
				return (0);
			i++;
		}
	}
	else
	{
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
