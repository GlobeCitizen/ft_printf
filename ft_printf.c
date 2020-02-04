/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:00:01 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/04 19:53:46 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./libft/libft.h"

void	format_props_bezero(t_props *p)
{
	p->i = 0;
	p->nprinted = 0;
	p->width = 0;
	p->precision = 0;
	p->minus = 0;
	p->zero = 0;
}

int		parser(const char *format, va_list ap, t_props *p, int pos)
{
	return pos;
}

int		formatparser(const char *format, va_list ap, t_props *p, int pos)
{
	while (format[pos])
	{
		if (format[pos] != '%')
			p ->nprinted += write(1, &format[pos], 1);
		else
		{
			if (!ft_strchr(SYMBOLS, format[pos + 1]))
				break ;
			while (ft_strchr(SYMBOLS, format[pos + 1]))
			{
				pos++;
				if (ft_strchr(CONVERSIONS, format[pos + 1]))
				{
					pos = parser(format, ap, p, pos) + 2;
					break ;
				}
				else
					pos = parser(format, ap, p, pos);
			}
		}
		pos++;
	}
	return(p->nprinted);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_props	*p;

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
	format_props_bezero(p);
	formatparser(format, args, p, 0);
	return (p->nprinted);
}
