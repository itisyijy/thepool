/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:00:11 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/03 19:22:38 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i = 0;
	while (i < size)
	{
		write(1, addr, 1);
		addr++;
		i++;
	}
}

int main()
{
	int i = 13;
	char c = 'A';
	char str[] = "hello";
	ft_print_memory(&i, sizeof(i));
	ft_print_memory(&c, sizeof(i));
	ft_print_memory(str, sizeof(str));
}
