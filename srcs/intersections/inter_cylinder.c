/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:42:39 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:08:57 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	check_cy_t(float t, t_object *cylinder, t_ray ray)
{
	t_vec3	hp;
	t_vec3	b;
	t_vec3	limits[2];

	b = add_vec3(cylinder->point[0],
			mult_vec3(cylinder->height, cylinder->vec));
	hp = add_vec3(ray.origin, mult_vec3(t, ray.direction));
	limits[0] = sub_vec3(hp, cylinder->point[0]);
	limits[1] = sub_vec3(hp, b);
	if (dot_product(cylinder->vec, limits[0]) <= 0.00001)
		return (0);
	if (dot_product(cylinder->vec, limits[1]) >= 0.00001)
		return (0);
	return (1);
}

static int	calculate_quadratic(float *a, float *b, float *f_tmp)
{
	float	dis;

	dis = (float)(pow(f_tmp[1], 2) - (4.0 * f_tmp[0] * f_tmp[2]));
	if (dis < 0.0)
		return (-1);
	*a = (-f_tmp[1] + sqrt(dis)) / (2.0 * f_tmp[0]);
	*b = (-f_tmp[1] - sqrt(dis)) / (2.0 * f_tmp[0]);
	return (1);
}

static int	get_delta_cy(float *t1, float *t2, t_object *obj, t_ray ray)
{
	t_vec3	v_tmp[2];
	float	f_tmp[3];

	v_tmp[0] = sub_vec3(ray.direction,
			mult_vec3(dot_product(ray.direction, obj->vec), obj->vec));
	f_tmp[0] = dot_product(v_tmp[0], v_tmp[0]);
	v_tmp[1] = sub_vec3(sub_vec3(ray.origin, obj->point[0]),
			mult_vec3(dot_product(sub_vec3(ray.origin, obj->point[0]),
					obj->vec), obj->vec));
	f_tmp[1] = 2 * dot_product(v_tmp[0], v_tmp[1]);
	f_tmp[2] = dot_product(v_tmp[1], v_tmp[1])
		- ((obj->diameter / 2) * (obj->diameter / 2));
	if (calculate_quadratic(t1, t2, f_tmp) == 1)
		return (1);
	return (-1);
}

float		find_intersection_cy(t_object *object, t_ray ray)
{
	float	t[2];
	float	final;

	final = -1.0;
	t[0] = INT_MAX;
	t[1] = INT_MAX;
	if (get_delta_cy(&t[0], &t[1], object, ray) != 1)
		return (final);
	if ((t[0] >= 0.00001) && check_cy_t(t[0], object, ray))
		final = t[0];
	if ((t[1] >= 0.00001) && check_cy_t(t[1], object, ray))
		if (t[1] < t[0])
			final = t[1];
	return (final);
}
