/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:45 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 14:59:07 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_vec3	get_normal_sp(t_object *obj, t_vec3 inter_point)
{
	return (normalize_vec3(sub_vec3(inter_point, obj->point[0])));
}

static t_vec3	get_normal_cy(t_object *obj, t_vec3 inter_point)
{
	float	a;
	t_vec3	b;

	b = sub_vec3(inter_point, obj->point[0]);
	a = dot_product(obj->vec, b);
	return (normalize_vec3(sub_vec3(b, mult_vec3(a, obj->vec))));
}

static t_vec3	get_normal_tr(t_object *obj)
{
	return (normalize_vec3(cross_product_vec3(sub_vec3(obj->point[1],
					obj->point[0]), sub_vec3(obj->point[2], obj->point[1]))));
}

t_vec3			get_normal(t_scene *scene, t_object *obj, t_vec3 inter_point)
{
	t_vec3	normal;

	normal = create_vec3(0, 0, 0);
	if (obj->type[0] == 's')
	{
		if (obj->type[1] == 'p')
			normal = get_normal_sp(obj, inter_point);
		else if (obj->type[1] == 'q')
			normal = obj->vec;
	}
	else if (obj->type[0] == 't' && obj->type[1] == 'r')
		normal = get_normal_tr(obj);
	else if (obj->type[0] == 'c' && obj->type[1] == 'y')
		normal = get_normal_cy(obj, inter_point);
	else if (obj->type[0] == 'p' && obj->type[1] == 'l')
		normal = obj->vec;
	if (dot_product(scene->ray.direction, normal) > 0.0)
	{
		normal.x = normal.x * -1.0;
		normal.y = normal.y * -1.0;
		normal.z = normal.z * -1.0;
	}
	return (normal);
}
