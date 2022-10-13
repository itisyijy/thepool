/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:46:40 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/12 18:14:07 by jeongyle         ###   ########.fr       */
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
	char	*tmp;
	char	*result;

	tmp = (char *)malloc(sizeof(char) * (str_size(str) + 1));
	if (result == NULL)
		return (NULL);
	result = tmp;
	while (*tmp)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = '\0';
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stocks;

	if (ac <= 0)
		return (NULL);
	stocks = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
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
	stocks[i] = (struct s_stock_str){0, 0, 0};
	return (stocks);
}
