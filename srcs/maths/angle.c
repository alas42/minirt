/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:51 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 17:27:34 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	cosinus_vec3(t_vec3 a, t_vec3 b)
{
	float	r;

	r = dot_product(a, b);
	r = r / (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2))
			* sqrt(pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2)));
	return (r);
}
