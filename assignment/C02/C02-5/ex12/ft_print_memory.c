/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:07:11 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/10 16:28:13 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	address_print(char *arr)
{
	int	i;

	i = 0;
	while (i < 16)
		write(1, &arr[i++], 1);
	write(1, ": ", 2);
}

void	char_hex(char *str, unsigned int size)
{
	unsigned int	count;

	if (size >= 16)
		size = 16;
	count = 0;
	while (*str != '\0' && count < size)
	{
		write(1, &"0123456789abcdef"[*str / 16], 1);
		write(1, &"0123456789abcdef"[*str++ % 16], 1);
		if (++count % 2 == 0)
			write(1, " ", 1);
	}
	if (*str == '\0' && count < size)
	{
		write(1, "00", 2);
		if (++count % 2 == 0)
			write(1, " ", 1);
	}
	while (count < 16)
	{
		write(1, "  ", 2);
		if (++count % 2 == 0)
			write(1, " ", 1);
	}
}

void	char_16(char *str, unsigned int size)
{
	unsigned int	count;

	if (size >= 16)
		size = 16;
	count = 0;
	while (*str != '\0' && count < size)
	{
		if (*str < 32 || *str > 126)
			write(1, ".", 1);
		else
			write(1, str, 1);
		count++;
		str++;
	}
	if (*str == '\0' && count < size)
		write(1, ".", 1);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;
	char			arr[16];
	char			*str;

	i = -1;
	if (size % 16 == 0)
		count = size / 16;
	else
		count = size / 16 + 1;
	str = (char *)addr;
	if (size == 0)
		return (addr);
	while (++i < count)
	{
		address_hex((unsigned long long)str, 15, arr);
		address_print(arr);
		char_hex(str, size);
		char_16(str, size);
		size -= 16;
		str += 16;
	}
	return (addr);
}

int main()
{
	char str[] = "0123456789abcdef";
	ft_print_memory(str, sizeof(str));
}
