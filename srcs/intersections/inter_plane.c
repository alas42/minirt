/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:42:58 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 17:20:30 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	find_intersection_pl(t_object *object, t_ray ray)
{
	float	denominator;
	float	solve;

	solve = 0;
	denominator = dot_product(ray.direction, object->vec);
	if (fabs(denominator) > 0.00001)
	{
		solve = dot_product(sub_vec3(object->point[0], ray.origin),
				object->vec) / denominator;
		if (solve >= 0.00001)
			return (solve);
	}
	return (-1);
}
