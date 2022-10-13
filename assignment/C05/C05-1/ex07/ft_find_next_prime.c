/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:10:56 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/06 20:28:11 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
{
	long long	prime;

	prime = 2;
	if (nb == 2)
		return (1);
	else if (nb % 2 == 0 || nb < 2)
		return (0);
	while (prime * prime < nb)
	{
		if (nb % prime == 0)
			return (0);
		prime++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	prime;

	if (is_prime(nb))
		return (nb);
	prime = nb + 1;
	while (1)
	{
		if (is_prime(prime))
			return (prime);
		prime++;
	}
}
