/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:55:10 by mahnich           #+#    #+#             */
/*   Updated: 2020/02/04 19:38:11 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define SYMBOLS "-0*.cspdiuxX%123456789"
# define FLAGS "-0*."
# define CONVERSIONS "cspdiuxX%"

int				ft_printf(const char *format, ...);

typedef struct	s_props
{
	int			i;
	int			nprinted;
	char		*format;
	int			minus;
	int			zero;
	int			width;
	int			precision;
}				t_props;

#endif
