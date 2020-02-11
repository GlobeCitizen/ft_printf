/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:55:10 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/11 20:01:41 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define SYMBOLS "-0*.cspdiuxX%123456789"
# define CONVERSIONS "cspdiuxX%"

typedef struct	s_props
{
	int			i;
	int			nprinted;
	char		*format;
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			precision_value;
	char		conversion;
	int			flag;
}				t_props;

int				ft_printf(const char *format, ...);

void			print(va_list ap, t_props *p);
void			printchar(va_list ap, t_props *p);
void			printstring(va_list ap, t_props *p);
void			printint(va_list ap, t_props *p);
void			printhex(va_list ap, t_props *p);
void			printunsigned(va_list ap, t_props *p);
void			printpercent(t_props *p);
void			printpointer(va_list ap, t_props *p);

int				abs(int n);
int				digitsize(int n, int b);
int				digitsizeu(unsigned long n, int b);
void			ft_putnbr_base_p(long n, long b, char c);
void			pass_minuses(const char *format, t_props *p);

#endif
