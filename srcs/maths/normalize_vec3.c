/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vec3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:44:40 by avogt             #+#    #+#             */
/*   Updated: 2020/11/15 17:44:41 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec3	normalize_vec3(t_vec3 v)
{
	float	len;

	len = sqrt(dot_product(v, v));
	if (len > 0.0)
		return (mult_vec3((1 / len), v));
	return (v);
}
