/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:15:23 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 12:23:19 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_pixel	**create_tab_pixel(t_scene *scene)
{
	t_pixel	**pixels;
	int		i;

	i = 0;
	pixels = (t_pixel **)malloc(sizeof(t_pixel *) * scene->resolution.y);
	if (!pixels)
	{
		pixels = NULL;
		ft_error("Allocation of tab pixels[*][]", scene);
	}
	while (i < scene->resolution.y)
	{
		pixels[i] = (t_pixel *)malloc(sizeof(t_pixel) * scene->resolution.x);
		if (!pixels[i])
		{
			i = i - 1;
			while (i >= 0)
				free(pixels[i--]);
			pixels = NULL;
			ft_error("Allocation of tab pixels[][*]", scene);
		}
		i++;
	}
	return (pixels);
}

static t_pixel	color_to_pixel(t_color color)
{
	t_pixel	pixel;

	pixel.b = (int)(fmin(1.0, color.blue) * 255);
	pixel.g = (int)(fmin(1.0, color.green) * 255);
	pixel.r = (int)(fmin(1.0, color.red) * 255);
	return (pixel);
}

static t_pixel	get_color_pixel(t_scene *scene)
{
	t_color		color;
	t_object	*hit;

	color = new_color(0.0, 0.0, 0.0);
	hit = intersect(scene);
	if (hit)
	{
		shading(scene, &color);
		color = mult_color(color, hit->color);
	}
	return (color_to_pixel(color));
}

void			raytracing_bmp(t_scene *scene)
{
	float	ij[2];
	t_ray	ray;
	t_pixel	**pixels;

	ij[0] = 0;
	pixels = NULL;
	pixels = create_tab_pixel(scene);
	while (ij[0] < scene->resolution.x)
	{
		ij[1] = 0;
		while (ij[1] < scene->resolution.y)
		{
			find_ray(scene, ij[0], ij[1]);
			ray = scene->ray;
			pixels[(int)ij[1]][(int)ij[0]] = get_color_pixel(scene);
			scene->ray = ray;
			ij[1] += 1;
		}
		ij[0] += 1;
	}
	save_in_bmp(scene, pixels);
}
