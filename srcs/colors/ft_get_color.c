/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:41:09 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:31:48 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	ft_get_color(const char *s, size_t *i)
{
	float	r;
	float	g;
	float	b;

	r = 0;
	g = 0;
	b = 0;
	r = ft_atof(s, i);
	if (!(skip_comma(s[*i], i)))
		return (new_color(-1, -1, -1));
	g = ft_atof(s, i);
	if (!(skip_comma(s[*i], i)))
		return (new_color(-1, -1, -1));
	b = ft_atof(s, i);
	if (r > 255.0 || b > 255.0 || g > 255.0 || r < 0.0 || b < 0.0 || g < 0.0)
		return (new_color(-1, -1, -1));
	return (new_color(r, g, b));
}
