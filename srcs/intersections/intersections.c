/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:43:10 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:04:36 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_object	*intersect(t_scene *scene)
{
	float		closest;
	float		m;
	t_list		*objs;
	t_object	*a;

	a = NULL;
	m = INT_MAX;
	closest = INT_MAX;
	objs = scene->object;
	while (objs)
	{
		closest = find_intersection(objs->content, scene->ray);
		if (closest > 0.0 && closest < m)
		{
			m = closest;
			scene->t = m;
			a = objs->content;
			scene->obj = a;
		}
		objs = objs->next;
	}
	return (a);
}

float		find_intersection(t_object *obj, t_ray ray)
{
	if (obj->type[0] == 's')
	{
		if (obj->type[1] == 'p')
			return (find_intersection_sp(obj, ray));
		else if (obj->type[1] == 'q')
			return (find_intersection_sq(obj, ray));
	}
	else if (obj->type[0] == 't' && obj->type[1] == 'r')
		return (find_intersection_tr(obj, ray));
	else if (obj->type[0] == 'c' && obj->type[1] == 'y')
		return (find_intersection_cy(obj, ray));
	else if (obj->type[0] == 'p' && obj->type[1] == 'l')
		return (find_intersection_pl(obj, ray));
	return (INT_MAX);
}
