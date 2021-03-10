/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:47:00 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 15:13:53 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		check_light(t_scene *scene, t_light *light, t_vec3 inter_point)
{
	t_vec3	light_direction;
	t_list	*act_obj;
	t_ray	shadow_ray;
	float	t;
	float	m;

	m = INT_MAX;
	light_direction = sub_vec3(light->p, inter_point);
	t = (float)sqrt(dot_product(light_direction, light_direction));
	shadow_ray.direction = light_direction;
	if (t > 0.0)
		shadow_ray.direction = mult_vec3((1.0 / t), light_direction);
	shadow_ray.origin = add_vec3(inter_point,
		mult_vec3(0.0001, shadow_ray.direction));
	act_obj = scene->object;
	while (act_obj)
	{
		m = find_intersection(act_obj->content, shadow_ray);
		if (m > 0.00001 && m < t)
			return (0);
		act_obj = act_obj->next;
	}
	return (1);
}

static float	get_ratio(t_vec3 inter_point, t_light *light, t_vec3 normal)
{
	float	ratio;
	t_vec3	n_l_i;

	n_l_i = normalize_vec3(sub_vec3(light->p, inter_point));
	ratio = light->ratio * cosinus_vec3(normal, n_l_i);
	return (ratio);
}

void			shading(t_scene *scene, t_color *color)
{
	t_vec3	inter_point;
	t_vec3	normal;
	t_list	*lights;
	float	angle;

	inter_point = add_vec3(scene->ray.origin,
			mult_vec3(scene->t, scene->ray.direction));
	normal = get_normal(scene, scene->obj, inter_point);
	get_color_with_ambiant(scene, color);
	angle = 0.0;
	lights = scene->light;
	while (lights)
	{
		angle = dot_product(normal, normalize_vec3(sub_vec3(
						((t_light *)lights->content)->p, inter_point)));
		if (check_light(scene, lights->content, inter_point) && angle > 0.0)
		{
			get_color_with_light(color, lights->content,
				get_ratio(inter_point, lights->content, normal));
		}
		lights = lights->next;
	}
}

void			raytracing(t_scene *scene)
{
	int			ij[2];
	t_color		color;
	t_ray		ray;
	t_object	*hit;

	ij[0] = 0;
	while (ij[0] < scene->resolution.x)
	{
		ij[1] = 0;
		while (ij[1] < scene->resolution.y)
		{
			color = new_color(0, 0, 0);
			find_ray(scene, ij[0], ij[1]);
			ray = scene->ray;
			hit = intersect(scene);
			if (hit != NULL)
				shading(scene, &color);
			if (hit != NULL)
				color = mult_color(color, hit->color);
			scene->ray = ray;
			put_color_px(&scene->img, ij[0], ij[1], color);
			ij[1]++;
		}
		ij[0]++;
	}
}
