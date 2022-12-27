/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:46:40 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/11 16:01:38 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_size(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*str_dup(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i] != '\0')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	while (j < i + 1)
	{
		result[j] = str[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stocks;

	if (ac <= 0)
		return (NULL);
	stocks = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (stocks == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stocks[i].size = str_size(av[i]);
		stocks[i].str = av[i];
		stocks[i].copy = str_dup(av[i]);
		i++;
	}
	stocks[i] = (t_stock_str){0, 0, 0};
	return (stocks);
}
