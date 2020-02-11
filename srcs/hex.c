/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:05:04 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 16:08:05 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		displaygapsx(t_props *p, int width, int precision, unsigned int n)
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
	new_width = width - len - zeros;
	if (n == 0 && precision == 0 && p->precision == 1)
		new_width = width - zeros;
	while (new_width-- > 0)
		p->nprinted += write(1, " ", 1);
}

void		displayzerosx(t_props *p, int width, int precision, unsigned int n)
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

void		print_right_x(unsigned int n, t_props *p, char c)
{
	displaygapsx(p, p->width, p->precision_value, n);
	displayzerosx(p, p->width, p->precision_value, n);
	if (!(n == 0 && p->precision_value == 0 && p->precision == 1))
		ft_putnbr_base(n, 16, c);
}

void		print_left_x(unsigned int n, t_props *p, char c)
{
	displayzerosx(p, p->width, p->precision_value, n);
	if (!(n == 0 && p->precision_value == 0 && p->precision == 1))
		ft_putnbr_base(n, 16, c);
	displaygapsx(p, p->width, p->precision_value, n);
}

void		printhex(va_list ap, t_props *p)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	if (p->minus == 1)
		print_left_x(n, p, p->conversion);
	else
		print_right_x(n, p, p->conversion);
	p->nprinted += digitsizeu(n, 16) - (n == 0 && p->precision == 1
			&& p->precision_value == 0);
}
