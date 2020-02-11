/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:26:39 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 15:41:54 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printchar(va_list ap, t_props *p)
{
	char c;

	if (p->conversion == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	if (p->minus == 0)
	{
		while (p->width-- > 1)
			p->nprinted += write(1, " ", 1);
		p->nprinted += write(1, &c, 1);
	}
	else
	{
		p->nprinted += write(1, &c, 1);
		while (p->width-- > 1)
			p->nprinted += write(1, " ", 1);
	}
}
