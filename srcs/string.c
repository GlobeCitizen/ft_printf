/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 23:07:27 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/06 04:08:49 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		displaygaps(char *str, int width, t_props *p)
{
	int	new_width;
	int	len;

	len = ft_strlen(str);
	new_width = width - len;
	if (p->precision == 1 && p->precision_value < len)
		new_width = width - p->precision_value;
	while (new_width-- >= 1)
		p->nprinted += write(1, " ", 1);
}

void		printer_right(char *str, t_props *p)
{
	int		precision;

	precision = p->precision_value;
	if (p->precision_value != 0)
	{
		displaygaps(str, p->width, p);
		while (precision-- > 0 && *str)
			p->nprinted += write(1, str++, 1);
	}
	else
	{
		displaygaps(str, p->width, p);
		if (p->precision == 0)
		{
			while (*str)
				p->nprinted += write(1, str++, 1);
		}
	}
}

void		printer_left(char *str, t_props *p)
{
	int		precision;
	char	*tmp;

	tmp = str;
	precision = p->precision_value;
	if (p->precision_value != 0)
	{
		while (precision-- > 0 && *str)
			p->nprinted += write(1, str++, 1);
		displaygaps(tmp, p->width, p);
	}
	else
	{
		if (p->precision == 0)
		{
			while (*str)
				p->nprinted += write(1, str++, 1);
		}
		displaygaps(tmp, p->width, p);
	}
}

void		printstring(va_list ap, t_props *p)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (p->minus == 0)
		printer_right(str, p);
	else
		printer_left(str, p);
}
