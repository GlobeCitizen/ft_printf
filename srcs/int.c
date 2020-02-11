/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:41:06 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 18:19:01 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		displaygapsint(t_props *p, int width, int precision, int n)
{
	int	len;
	int zeros;
	int	new_width;

	len = digitsize(n, 10);
	zeros = 0;
	if (p->precision == 0 && p->zero == 1)
		zeros = width - len;
	else if (precision > len - (n < 0))
		zeros = precision - (len - (n < 0));
	new_width = width - len - zeros - (n == 0 && p->precision == 0);
	while (new_width-- > 0)
		p->nprinted += write(1, " ", 1);
}

void		displayzeros(t_props *p, int width, int precision, int n)
{
	int	len;
	int	new_width;

	len = digitsize(n, 10);
	new_width = width - len - (n == 0);
	if (precision > len - (n < 0))
	{
		new_width = precision - (len - (n < 0));
		while (new_width-- > 0)
			p->nprinted += write(1, "0", 1);
	}
	else if (p->precision == 0 && p->zero == 1)
	{
		while (new_width-- > 0)
			p->nprinted += write(1, "0", 1);
	}
}

void		print_right(int n, t_props *p)
{
	displaygapsint(p, p->width, p->precision_value, n);
	if (n < 0)
		p->nprinted += write(1, "-", 1);
	displayzeros(p, p->width, p->precision_value, n);
	if (n != 0)
		ft_putnbr_base(abs(n), 10, 'x');
	if (n == 0 && p->precision == 0)
		p->nprinted += write(1, "0", 1);
}

void		print_left(int n, t_props *p)
{
	if (n < 0)
		p->nprinted += write(1, "-", 1);
	displayzeros(p, p->width, p->precision_value, n);
	if (n != 0)
		ft_putnbr_base(abs(n), 10, 'x');
	if (n == 0 && p->precision == 0)
		p->nprinted += write(1, "0", 1);
	displaygapsint(p, p->width, p->precision_value, n);
}

void		printint(va_list ap, t_props *p)
{
	int n;

	n = va_arg(ap, int);
	if (p->minus == 1)
		print_left(n, p);
	else
		print_right(n, p);
	p->nprinted += digitsize(n, 10) - (n < 0);
}
