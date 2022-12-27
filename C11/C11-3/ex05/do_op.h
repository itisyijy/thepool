/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:57:14 by jeongyle          #+#    #+#             */
/*   Updated: 2022/09/13 16:25:58 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

typedef int	(*t_op)(int, int);

int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		ft_plus(int a, int b);
int		ft_minus(int a, int b);
int		ft_multiple(int a, int b);
int		ft_divide(int a, int b);
int		ft_mod(int a, int b);

#endif
