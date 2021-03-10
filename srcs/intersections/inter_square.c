/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:43:40 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 17:23:02 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	find_intersection_sq(t_object *object, t_ray ray)
{
	float	t;
	float	b;
	t_vec3	v;

	v = create_vec3(0, 0, 0);
	t = find_intersection_pl(object, ray);
	b = 0.0;
	if (t >= 0.00001)
	{
		v = sub_vec3(add_vec3(ray.origin,
					mult_vec3(t, ray.direction)), object->point[0]);
		b = object->height / 2;
		if (fabs(v.x) <= b && fabs(v.y) <= b && fabs(v.z) <= b)
			return (t);
	}
	return (-1);
}
