/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:10:28 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 20:00:39 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int		abs(int n)
{
	int	absolue;

	absolue = (n > 0) ? n : -n;
	return (absolue);
}

int		digitsize(int n, int b)
{
	int	count;

	count = (n < 0) ? 1 : 0;
	n = (n > 0) ? n : -n;
	while (n > 0)
	{
		n /= b;
		count++;
	}
	if (n == -2147483648)
		return (11);
	return (count);
}

int		digitsizeu(unsigned long n, int b)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= b;
		count++;
	}
	return (count);
}

void	ft_putnbr_base_p(long n, long b, char c)
{
	char			*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < b)
		ft_putchar(base[n]);
	else
	{
		ft_putnbr_base_p(n / b, b, c);
		ft_putnbr_base_p(n % b, b, c);
	}
}

void	pass_minuses(const char *format, t_props *p)
{
	int flag;

	flag = 0;
	while (format[p->i + 1] == '-')
	{
		flag = 1;
		p->i++;
	}
	if (flag == 1)
		p->i -= 1;
}
