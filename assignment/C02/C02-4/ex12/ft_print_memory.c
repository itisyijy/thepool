/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:07:11 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/06 22:32:40 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	address_hex(unsigned long long llu, int index, char *arr)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (llu >= 16)
		address_hex(llu / 16, index - 1, arr);
	else
	{
		arr[index] = '0';
		if (index > 0)
			address_hex(0, index - 1, arr);
	}
	arr[index] = hex[llu % 16];
}

void	char_hex(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0' && count < 16)
	{
		ft_putchar("0123456789abcdef"[*str / 16]);
		ft_putchar("0123456789abcdef"[*str % 16]);
		if (++count % 2 == 0)
			write(1, " ", 1);
		str++;
	}
	if (count < 16)
	{
		if (*str == '\0')
			write(1, "00", 2);
		if (++count % 2 == 0)
			write(1, " ", 1);
		while (count < 16)
		{
			write(1, "  ", 2);
			if (++count % 2 == 0)
				write(1, " ", 1);
		}
	}
}

void	char_16(char *str, int i, int line)
{
	int	count;

	count = 0;
	while (*str != '\0' && count < 16)
	{
		if (*str < 32 || *str > 126)
			write(1, ".", 1);
		else
			ft_putchar(*str);
		count++;
		str++;
	}
	if (count < 16)
	{
		if (*str == '\0')
			write(1, ".", 1);
	}
	if (i + 1 <= line)
		write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	char			arr[16];
	char			*str;

	i = 0;
	j = 0;
	if (size % 16 == 0)
		count = size / 16;
	else
		count = size / 16 + 1;
	str = (char *)addr;
	if (size == 0)
		return (addr);
	while (i < count)
	{
		address_hex((unsigned long long)str, 15, arr);
		j = 0;
		while (j < 16)
			ft_putchar(arr[j++]);
		write(1, ": ", 2);
		char_hex(str);
		char_16(str, i, count);
		str += 16;
		i++;
	}
	return (addr);
}
