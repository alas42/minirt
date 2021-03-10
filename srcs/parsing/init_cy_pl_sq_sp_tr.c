/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cy_pl_sq_sp_tr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:45:50 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 15:12:31 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*init_cylindre(char *line, t_scene *scene)
{
	size_t		i;
	t_object	*object;
	t_vec3		vec;

	object = NULL;
	i = 2;
	object = (t_object *)malloc(sizeof(t_object));
	if (!(object))
		return ("Failed allocation of cylinder");
	object->type[0] = 'c';
	object->type[1] = 'y';
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Cylinder point given is incorrect"));
	object->point[0] = vec;
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Cylinder vector given is incorrect"));
	object->vec = vec;
	object->diameter = ft_get_diameter(line, &i);
	object->height = ft_get_height(line, &i);
	object->color = ft_get_color(line, &i);
	if (is_color_null(object->color))
		return (free_o_parsed(object, "Cylinder color isn't in range[0,255]"));
	ft_lstadd_back(&scene->object, ft_lstnew(object));
	return (check_data_cy(object));
}

char	*init_plane(char *line, t_scene *scene)
{
	size_t		i;
	t_object	*object;
	t_vec3		vec;

	object = NULL;
	i = 2;
	object = (t_object *)malloc(sizeof(t_object));
	if (!(object))
		return ("Failed allocation of plane");
	object->type[0] = 'p';
	object->type[1] = 'l';
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Plane point given is incorrect"));
	object->point[0] = vec;
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Plane vector given is incorrect"));
	object->vec = vec;
	object->color = ft_get_color(line, &i);
	if (is_color_null(object->color))
		return (free_o_parsed(object, "Plane color isn't in range[0,255]"));
	ft_lstadd_back(&scene->object, ft_lstnew(object));
	return (check_data_pl(object));
}

char	*init_sphere(char *line, t_scene *scene)
{
	size_t		i;
	t_object	*object;
	t_vec3		vec;

	object = NULL;
	i = 2;
	object = (t_object *)malloc(sizeof(t_object));
	if (!(object))
		return ("Failed allocation of sphere");
	object->type[0] = 's';
	object->type[1] = 'p';
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Sphere point given is incorrect"));
	object->point[0] = vec;
	object->vec = create_vec3(0, 0, 0);
	object->diameter = ft_get_diameter(line, &i);
	if (object->diameter <= 0)
		free_o_parsed(object, "Sphere diameter is < 0 or unprecised");
	object->color = ft_get_color(line, &i);
	if (is_color_null(object->color))
		return (free_o_parsed(object, "Sphere color isn't in range[0,255]"));
	ft_lstadd_back(&scene->object, ft_lstnew(object));
	return (NULL);
}

char	*init_square(char *line, t_scene *scene)
{
	size_t		i;
	t_object	*object;
	t_vec3		vec;

	object = NULL;
	i = 2;
	object = (t_object *)malloc(sizeof(t_object));
	if (!(object))
		return ("Failed allocation of square");
	object->type[0] = 's';
	object->type[1] = 'q';
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Square point given is incorrect"));
	object->point[0] = vec;
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Square vector given is incorrect"));
	object->vec = vec;
	object->height = ft_get_height(line, &i);
	object->color = ft_get_color(line, &i);
	if (is_color_null(object->color))
		return (free_o_parsed(object, "Square color isn't in range[0,255]"));
	ft_lstadd_back(&scene->object, ft_lstnew(object));
	return (check_data_sq(object));
}

char	*init_triangle(char *line, t_scene *scene)
{
	size_t		i;
	t_object	*object;
	t_vec3		vec;

	object = NULL;
	i = 2;
	object = (t_object *)malloc(sizeof(t_object));
	if (!(object))
		return ("Failed allocation of triangle");
	object->type[0] = 't';
	object->type[1] = 'r';
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Triangle point[0] given is incorrect"));
	object->point[0] = vec;
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Triangle point[1] given is incorrect"));
	object->point[1] = vec;
	if (!(ft_get_vec3(line, &vec, &i)))
		return (free_o_parsed(object, "Triangle point[2] given is incorrect"));
	object->point[2] = vec;
	object->color = ft_get_color(line, &i);
	if (is_color_null(object->color))
		return (free_o_parsed(object, "Triangle color isn't in range[0,255]"));
	ft_lstadd_back(&scene->object, ft_lstnew(object));
	return (NULL);
}
