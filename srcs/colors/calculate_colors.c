/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:40:46 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:34:50 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	new_color(float r, float g, float b)
{
	t_color	c;

	c.red = r / 255.0;
	c.green = g / 255.0;
	c.blue = b / 255.0;
	return (c);
}

t_color	mult_color(t_color a, t_color b)
{
	t_color	c;

	c.red = a.red * b.red;
	c.green = a.green * b.green;
	c.blue = a.blue * b.blue;
	return (c);
}

void	get_color_with_ambiant(t_scene *scene, t_color *color)
{
	color->red = color->red
		+ (scene->amblight.color.red * scene->amblight.ratio);
	color->green = color->green
		+ (scene->amblight.color.green * scene->amblight.ratio);
	color->blue = color->blue
		+ (scene->amblight.color.blue * scene->amblight.ratio);
}

void	get_color_with_light(t_color *color, t_light *light, float r)
{
	color->red = color->red + (light->color.red * r);
	color->green = color->green + (light->color.green * r);
	color->blue = color->blue + (light->color.blue * r);
}
