/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:00:01 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 20:11:23 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

void	props_bezero(t_props *p)
{
	p->i = 0;
	p->width = 0;
	p->minus = 0;
	p->zero = 0;
	p->precision_value = 0;
	p->conversion = 0;
	p->precision = 0;
	p->flag = 0;
}

void	flagsparser0(const char *format, va_list ap, t_props *p)
{
	if (format[p->i] == '.')
	{
		p->precision = 1;
		p->flag = 1;
		if (format[p->i + 1] == '*')
			p->precision_value = va_arg(ap, int);
		else if (ft_strchr("0123456789-", format[p->i + 1]))
			p->precision_value = ft_atoi(&format[p->i + 1]);
	}
}

int		flagsparser(const char *format, va_list ap, t_props *p, int pos)
{
	int	in;

	in = !!ft_strchr("-0", format[pos + 1]);
	p->i = pos;
	pass_minuses(format, p);
	pos = p->i;
	while (!ft_strchr(CONVERSIONS, format[++p->i]))
	{
		if (format[p->i] == '-')
			p->minus = 1;
		if (format[p->i] == '0' && !ft_isdigit(format[p->i - 1]) && !p->flag)
			p->zero = 1;
		if (format[p->i] == '*' && p->flag == 0)
		{
			p->flag = 1;
			p->width = va_arg(ap, int);
		}
		else if (p->flag != 1)
			p->width = ft_atoi(&format[pos + 1 + in]);
		flagsparser0(format, ap, p);
	}
	return (p->i);
}

int		formatparser(const char *format, va_list ap, t_props *p, int pos)
{
	while (format[pos])
	{
		if (format[pos] != '%')
			p->nprinted += write(1, &format[pos], 1);
		else
		{
			if (!ft_strchr(SYMBOLS, format[pos + 1]))
				break ;
			else
			{
				props_bezero(p);
				pos = flagsparser(format, ap, p, pos);
				p->conversion = format[p->i];
				if (p->conversion == 0)
					break ;
				print(ap, p);
			}
		}
		pos++;
	}
	return (p->nprinted);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_props	*p;
	int		ret;

	va_start(args, format);
	if (!(p = (t_props *)malloc(sizeof(t_props))))
		return (0);
	if (!format)
		return (0);
	if (format[0] == '%' && ft_strlen(format) == 1)
	{
		write(1, "", 1);
		return (0);
	}
	p->nprinted = 0;
	ret = formatparser(format, args, p, 0);
	va_end(args);
	free(p);
	return (ret);
}
