/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:00:09 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/08 18:10:09 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word_count(char *str, char *charset)
{
	int	i;
	int	j;
	int	flag;
	int	count;

	count = 0;
	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != charset[j] && charset[j] != '\0')
			j++;
		if (charset[j] == '\0' && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (charset[j] != '\0')
			flag = 0;
		i++;
	}
	return (count);
}

int	word_len(char *str, char *charset)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != charset[j] && charset[j] != '\0')
			j++;
		if (charset[j] == '\0')
			len++;
		else
			return (len);
		i++;
	}
	return (len);
}

char	*word_assign(char *loc, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		loc[i] = str[i];
		i++;
	}
	loc[i] = '\0';
	return (str + i);
}

char	*charset_check(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		while (*str != charset[i] && charset[i])
			i++;
		if (charset[i] == '\0')
			break ;
		else
			str++;
	}
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		count;
	int		len;
	char	**split;

	count = word_count(str, charset);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	i = -1;
	while (++i < count)
	{
		str = charset_check(str, charset);
		len = word_len(str, charset);
		split[i] = (char *)malloc(sizeof(char) * (len + 1));
		str = word_assign(split[i], str, len);
	}
	split[i] = NULL;
	return (split);
}
