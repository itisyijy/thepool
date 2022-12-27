/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:55:39 by jeongyle          #+#    #+#             */
/*   Updated: 2022/08/25 17:32:32 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *left, int *right)
{
	int	tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[i])
				swap(tab + j, tab + i);
			j++;
		}
		i++;
	}
}
