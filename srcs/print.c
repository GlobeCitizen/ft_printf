/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:01:03 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 17:24:31 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print(va_list ap, t_props *p)
{
	if (p->width < 0)
	{
		p->minus = 1;
		p->zero = 0;
		p->width = p->width * -1;
	}
	if (p->precision_value < 0)
	{
		p->precision_value = 0;
		p->precision = 0;
	}
	if (p->conversion == 'c')
		printchar(ap, p);
	if (p->conversion == 's')
		printstring(ap, p);
	if (p->conversion == 'p')
		printpointer(ap, p);
	if (p->conversion == 'u')
		printunsigned(ap, p);
	if (p->conversion == 'd' || p->conversion == 'i')
		printint(ap, p);
	if (p->conversion == 'x' || p->conversion == 'X')
		printhex(ap, p);
	if (p->conversion == '%')
		printpercent(p);
}
