/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:43:22 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 17:21:11 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	find_intersection_sp(t_object *object, t_ray ray)
{
	t_vec3	oc;
	float	abc[3];
	float	discriminant;
	float	roots[2];

	roots[0] = INT_MAX;
	roots[1] = INT_MAX;
	oc = sub_vec3(ray.origin, object->point[0]);
	abc[0] = dot_product(ray.direction, ray.direction);
	abc[1] = 2.0 * dot_product(ray.direction, oc);
	abc[2] = dot_product(oc, oc) - (object->diameter / 2)
		* (object->diameter / 2);
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0.0)
		return (-1.0);
	roots[0] = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
	roots[1] = (-abc[1] + sqrt(discriminant)) / (2.0 * abc[0]);
	if ((roots[0] >= 0.00001) && (roots[0] < INT_MAX) && (roots[0] < roots[1]))
		return (roots[0]);
	if ((roots[1] >= 0.00001) && (roots[1] < INT_MAX))
		return (roots[1]);
	return (-1.0);
}
