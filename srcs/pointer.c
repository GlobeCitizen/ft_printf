/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:05:21 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 18:32:22 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		displaygapsp(t_props *p, int width, int precision, unsigned long n)
{
	int	len;
	int zeros;
	int	new_width;

	len = digitsizeu(n, 16);
	zeros = 0;
	if (p->precision == 0 && p->zero == 1)
		zeros = width - len;
	else if (precision > len)
		zeros = precision - len;
	new_width = width - len - zeros - 2;
	if (n == 0 && precision == 0 && p->precision == 1)
		new_width = width - zeros - 2;
	while (new_width-- > 0)
		p->nprinted += write(1, " ", 1);
}

void		displayzerosp(t_props *p, int width, int precision, unsigned long n)
{
	int	len;
	int	new_width;

	len = digitsizeu(n, 16);
	new_width = width - len;
	if (precision > len)
	{
		new_width = precision - len;
		while (new_width-- > 0)
			p->nprinted += write(1, "0", 1);
	}
	else if (p->precision == 0 && p->zero == 1)
	{
		while (new_width-- > 0)
			p->nprinted += write(1, "0", 1);
	}
}

void		print_right_p(unsigned long n, t_props *p)
{
	displaygapsp(p, p->width, p->precision_value, n);
	displayzerosp(p, p->width, p->precision_value, n);
	p->nprinted += write(1, "0x", 2);
	if (!(n == 0 && p->precision_value == 0 && p->precision == 1))
		ft_putnbr_base_p(n, 16, 'x');
}

void		print_left_p(unsigned long n, t_props *p)
{
	displayzerosp(p, p->width, p->precision_value, n);
	p->nprinted += write(1, "0x", 2);
	if (!(n == 0 && p->precision_value == 0 && p->precision == 1))
		ft_putnbr_base_p(n, 16, 'x');
	displaygapsp(p, p->width, p->precision_value, n);
}

void		printpointer(va_list ap, t_props *p)
{
	long	n;

	n = (long)va_arg(ap, void *);
	if (p->minus == 1)
		print_left_p(n, p);
	else
		print_right_p(n, p);
	p->nprinted += digitsizeu(n, 16) - (n == 0 && p->precision == 1
			&& p->precision_value == 0);
}
