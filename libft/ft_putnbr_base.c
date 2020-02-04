/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:44:27 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/04 18:55:24 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned int n, unsigned int b)
{
	char			*base;

	base = "0123456789abcdef";
	if (n < 0)
		ft_putchar('-');
	n = (n < 0) ? n * -1 : n;
	if (n < b)
		ft_putchar(base[n]);
	else
	{
		ft_putnbr_base(n / b, b);
		ft_putnbr_base(n % b, b);
	}
}
