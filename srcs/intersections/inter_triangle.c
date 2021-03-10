/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:43:53 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:08:44 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static float	ray_to_plane(t_vec3 vertex, t_vec3 tnorm, t_ray ray)
{
	float	denominator;
	float	solve;

	solve = 0;
	denominator = dot_product(ray.direction, tnorm);
	if (fabs(denominator) > 0.00001)
	{
		solve = dot_product(sub_vec3(vertex, ray.origin),
				tnorm) / denominator;
		if (solve >= 0.00001)
			return (solve);
	}
	return (-1);
}

static int		inside_edges(t_vec3 tnorm, t_object *object, t_vec3 p)
{
	t_vec3	edges[3];
	t_vec3	pl_vect;

	edges[0] = sub_vec3(object->point[1], object->point[0]);
	edges[1] = sub_vec3(object->point[2], object->point[1]);
	edges[2] = sub_vec3(object->point[0], object->point[2]);
	pl_vect = sub_vec3(p, object->point[0]);
	if (dot_product(tnorm, cross_product_vec3(edges[0], pl_vect)) < 0.0)
		return (-1);
	pl_vect = sub_vec3(p, object->point[1]);
	if (dot_product(tnorm, cross_product_vec3(edges[1], pl_vect)) < 0.0)
		return (-1);
	pl_vect = sub_vec3(p, object->point[2]);
	if (dot_product(tnorm, cross_product_vec3(edges[2], pl_vect)) < 0.0)
		return (-1);
	return (1);
}

float			find_intersection_tr(t_object *object, t_ray ray)
{
	t_vec3	edges[2];
	t_vec3	tnorm;
	float	t;
	t_vec3	point_plane;

	point_plane = create_vec3(0, 0, 0);
	edges[0] = sub_vec3(object->point[1], object->point[0]);
	edges[1] = sub_vec3(object->point[2], object->point[0]);
	tnorm = normalize_vec3(cross_product_vec3(edges[0], edges[1]));
	t = ray_to_plane(object->point[0], tnorm, ray);
	if (t >= 0.00001)
	{
		point_plane = add_vec3(ray.origin,
				mult_vec3(t, ray.direction));
		if (inside_edges(tnorm, object, point_plane) == 1)
			return (t);
	}
	return (-1);
}
