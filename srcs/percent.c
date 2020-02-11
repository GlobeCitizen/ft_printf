/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:09:18 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 18:35:09 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printpercent(t_props *p)
{
	if (p->minus == 0)
	{
		if (p->zero == 0)
		{
			while (p->width-- > 1)
				p->nprinted += write(1, " ", 1);
			p->nprinted += write(1, "%", 1);
		}
		else
		{
			while (p->width-- > 1)
				p->nprinted += write(1, "0", 1);
			p->nprinted += write(1, "%", 1);
		}
	}
	else
	{
		p->nprinted += write(1, "%", 1);
		while (p->width-- > 1)
			p->nprinted += write(1, " ", 1);
	}
}
