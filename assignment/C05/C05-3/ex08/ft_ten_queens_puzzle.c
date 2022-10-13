/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:33:26 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/12 16:25:18 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_coor(char *arr)
{
	int	i;

	i = 0;
	while (i < 10)
		write(1, &arr[i++], 1);
	write(1, "\n", 1);
}

int	check(char *arr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (arr[i] == arr[index])
			return (0);
		if (index - i == arr[i] - arr[index])
			return (0);
		if (index - i == arr[index] - arr[i])
			return (0);
		i++;
	}
	return (1);
}

void	where(char *arr, int index, int *count)
{
	int	i;

	i = 0;
	if (index == 10)
	{
		print_coor(arr);
		*count += 1;
		return ;
	}
	while (i < 10)
	{
		arr[index] = i + '0';
		if (check(arr, index))
			where(arr, index + 1, count);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		i;
	int		count;
	char	arr[10];

	i = 0;
	count = 0;
	while (i < 10)
		arr[i++] = '0';
	where(arr, 0, &count);
	return (count);
}
