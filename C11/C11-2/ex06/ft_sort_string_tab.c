/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:21:13 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/13 15:45:10 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	if (tab == 0)
		return ;
	while (tab[size] != 0)
		size++;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
