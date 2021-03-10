/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:45:40 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 12:42:32 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	ft_get_vec3(const char *s, t_vec3 *vec, size_t *i)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
	vec->x = ft_atof(s, i);
	if (!(skip_comma(s[*i], i)))
		return (0);
	vec->y = ft_atof(s, i);
	if (!(skip_comma(s[*i], i)))
		return (0);
	vec->z = ft_atof(s, i);
	if (skip_comma(s[*i], i))
		return (0);
	return (1);
}
