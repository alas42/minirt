/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:46:38 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:05:55 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		get_fov_camera(t_camera camera)
{
	return (camera.fov);
}

static float	get_vp_coords(t_camera camera, char coord)
{
	if (coord == 'x')
		return (camera.view_point.x);
	else if (coord == 'y')
		return (camera.view_point.y);
	else if (coord == 'z')
		return (camera.view_point.z);
	else
		return (0.0);
}

void			find_ray(t_scene *scene, int test_i, int test_j)
{
	float	width;
	float	height;
	float	fov;
	float	ratio;
	t_vec3	pixel;

	fov = get_fov_camera(scene->a_camera);
	width = (float)scene->resolution.x;
	height = (float)scene->resolution.y;
	ratio = width / height;
	pixel.x = (2.0 * (((float)test_i + 0.5) / width) - 1.0) * ratio
		* tan(((fov / 2.0) * M_PI) / 180);
	pixel.y = (1.0 - 2.0 * (((float)test_j + 0.5) / height))
		* tan(((fov / 2.0) * M_PI) / 180);
	pixel.z = 1;
	scene->ray.direction = normalize_vec3(
			mult_mat3_vec3(scene->a_camera.cam_w, pixel));
	scene->ray.origin.x = get_vp_coords(scene->a_camera, 'x');
	scene->ray.origin.y = get_vp_coords(scene->a_camera, 'y');
	scene->ray.origin.z = get_vp_coords(scene->a_camera, 'z');
}
