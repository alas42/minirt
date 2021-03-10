/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:15:46 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:04:03 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	free_camera(t_list **camera)
{
	t_list	*ptr;

	ptr = NULL;
	while (*camera)
	{
		ptr = *camera;
		*camera = (*camera)->next;
		free(ptr->content);
		free(ptr);
	}
	*camera = NULL;
}

static void	free_object(t_list **object)
{
	t_list	*o;

	o = NULL;
	while (*object)
	{
		o = *object;
		*object = (*object)->next;
		free(o->content);
		free(o);
	}
	*object = NULL;
}

static void	free_light(t_list **light)
{
	t_list	*l;

	l = NULL;
	while (*light)
	{
		l = *light;
		*light = (*light)->next;
		free(l->content);
		free(l);
	}
	*light = NULL;
}

static void	free_img(t_scene *scene)
{
	mlx_destroy_image(scene->mlx_ptr, scene->img.ptr);
	scene->img.addr = NULL;
	scene->img.ptr = NULL;
}

void		free_scene(t_scene *scene)
{
	if (scene->camera)
		free_camera(&(scene->camera));
	if (scene->light)
		free_light(&(scene->light));
	if (scene->object)
		free_object(&(scene->object));
	if (scene->img.ptr)
		free_img(scene);
	free(scene);
	scene = NULL;
}
