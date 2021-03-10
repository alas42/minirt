/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_parsed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:11 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 18:02:19 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*check_data_cy(t_object *o)
{
	if (!check_range_vec3(o->vec))
		return ("Cylinder direction isn't in [-1, 1]");
	if (is_vec_null(o->vec))
		return ("Cylinder direction is null");
	if (o->diameter <= 0)
		return ("Cylinder diameter is <= 0");
	if (o->height <= 0)
		return ("Cylinder height is <= 0");
	o->vec = normalize_vec3(o->vec);
	return (NULL);
}

char	*check_data_sq(t_object *o)
{
	if (!check_range_vec3(o->vec))
		return ("Square direction isn't in [-1, 1]");
	if (is_vec_null(o->vec))
		return ("Square direction is null");
	if (o->height <= 0)
		return ("Square height is <= 0");
	o->vec = normalize_vec3(o->vec);
	return (NULL);
}

char	*check_data_pl(t_object *o)
{
	if (!check_range_vec3(o->vec))
		return ("Plane direction isn't in [-1, 1]");
	if (is_vec_null(o->vec))
		return ("Plane direction is null");
	o->vec = normalize_vec3(o->vec);
	return (NULL);
}

char	*check_data_camera(t_camera *cam)
{
	if (!(check_range_vec3(cam->vec)))
		return (free_c_parsed(cam, "Camera's direction should be bw [0,1]"));
	if (is_vec_null(cam->vec))
		return (free_c_parsed(cam, "Camera's dir vector is null"));
	if (cam->fov > 180 || cam->fov < 0)
		return (free_c_parsed(cam, "Camera fov isn't in [0,180] range"));
	cam->vec = normalize_vec3(cam->vec);
	return (NULL);
}
