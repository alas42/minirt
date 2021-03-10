/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_r_a_c_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:46:00 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 15:13:24 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*init_light(char *line, t_scene *scene)
{
	t_light	*light;
	t_vec3	vec;
	size_t	i;

	i = 1;
	light = NULL;
	light = (t_light *)malloc(sizeof(t_light));
	if (!(light))
		return ("Allocation of light struc failed");
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_l_parsed(light, "Light point given is incorrect"));
	light->p = vec;
	light->ratio = ft_get_ratio(line, &i);
	if (light->ratio > 1.0 || light->ratio < 0.0)
		return (free_l_parsed(light, "Light ratio isn't in range[0,1]"));
	light->color = ft_get_color(line, &i);
	if (is_color_null(light->color))
		return (free_l_parsed(light, "Light color isn't in range[0,255]"));
	ft_lstadd_back(&scene->light, ft_lstnew(light));
	return (NULL);
}

char	*init_camera(char *line, t_scene *scene)
{
	size_t		i;
	t_vec3		vec2;
	t_vec3		vec;
	t_camera	*cam;

	cam = NULL;
	i = 1;
	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!(cam))
		return ("Allocation of camera struc failed");
	if (!(ft_get_vec3(line, &vec2, &i)))
		return (free_c_parsed(cam, "Camera position given is incorrect"));
	cam->view_point = vec2;
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_c_parsed(cam, "Camera vector given is incorrect"));
	cam->vec = vec;
	cam->fov = ft_get_fov(line, &i);
	cam->cam_w = new_mat3();
	ft_lstadd_back(&scene->camera, ft_lstnew(cam));
	return (check_data_camera(cam));
}

char	*init_amblight(char *line, t_scene *scene)
{
	size_t	i;

	i = 1;
	if (scene->amblight.ratio != -1)
		return ("Amblight needs only one declaration, more detected");
	scene->amblight.ratio = ft_get_ratio(line, &i);
	if (scene->amblight.ratio > 1.0 || scene->amblight.ratio < 0.0)
		return ("Ambiant light's ratio isn't in range[0,1]");
	scene->amblight.color = ft_get_color(line, &i);
	if (is_color_null(scene->amblight.color))
		return ("Ambiant light's color isn't in range[0,255]");
	return (NULL);
}

char	*init_resolution(char *line, t_scene *scene)
{
	size_t	i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 1;
	if (scene->resolution.x != -1)
		return ("Resolution needs only one declaration, more detected");
	x = (int)ft_atof(line, &i);
	y = (int)ft_atof(line, &i);
	if (x > 0 && y > 0)
	{
		scene->resolution.x = x;
		scene->resolution.y = y;
	}
	else
		return ("Resolutions values should be > 0");
	return (NULL);
}
