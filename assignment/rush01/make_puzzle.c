/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_puzzle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:54:12 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/03 19:18:29 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdblib.h>
/*
void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}

void	num_case(char *input, int s, int r)
{
	int		i;

	if (s == r)
	{
		return ;
	}
	i = s;
	while (i < 4)
	{
		swap(&input[i], &input[s]);
		num_case(input, s + 1, r);
		swap(&input[i], &input[s]);
		i++;
	}
	input[i] = '\0';
}
*/

char	**make_puzzle(char **arr)
{
	while ()
	{

	}
	return ;
}

int	main()
{
	char **candidate;
	int i = 0;
	candidate = (char **)malloc(sizeof(char *) * 24);
	while (i < 24)
		candidate[i++] = (char *)malloc(sizeof(char) * 5);

}
