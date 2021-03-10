/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:46:08 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:05:41 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	check_scene_obj(t_scene *scene)
{
	if (scene->amblight.ratio == -1)
		ft_error("No ambiant light was given", scene);
	if (scene->resolution.x == -1)
		ft_error("No resolution was given", scene);
	if (scene->camera == NULL)
		ft_error("No camera was given", scene);
}

static char	*init_obj_multiple(char *line, char *id, t_scene *scene)
{
	if (id[0] == 'c' && id[1] == 'y')
		return (init_cylindre(line, scene));
	else if (id[0] == 's')
	{
		if (id[1] == 'p')
			return (init_sphere(line, scene));
		else if (id[1] == 'q')
			return (init_square(line, scene));
	}
	else if (id[0] == 'p' && id[1] == 'l')
		return (init_plane(line, scene));
	else if (id[0] == 't' && id[1] == 'r')
		return (init_triangle(line, scene));
	return ("Scene wrongly formatted : object does not exist");
}

static char	*init_obj_single(char *line, char id, t_scene *scene)
{
	if (id == 'R')
		return (init_resolution(line, scene));
	else if (id == 'A')
		return (init_amblight(line, scene));
	else if (id == 'c')
		return (init_camera(line, scene));
	else if (id == 'l')
		return (init_light(line, scene));
	return ("Scene wrongly formatted : Object does not exist");
}

static char	*search_obj(char *line, t_scene *scene)
{
	size_t	i;

	i = 0;
	while (ft_isalpha(line[i]) && line[i] != '\0')
		i++;
	if (i == 1)
	{
		if (line[i - 1] == 'R' || line[i - 1] == 'A'
			|| line[i - 1] == 'c' || line[i - 1] == 'l')
			return (init_obj_single(line, line[i - 1], scene));
		return ("Scene wrongly formatted : Object does not exist");
	}
	else if (i == 2)
	{
		if (line[i - 2] == 'c' || line[i - 2] == 's'
			|| line[i - 2] == 'p' || line[i - 2] == 't')
			return (init_obj_multiple(line, &line[i - 2], scene));
		return ("Scene wrongly formatted : Object does not exist");
	}
	else
		return (NULL);
}

void		parse_file(char *filename, t_scene *scene)
{
	char	*line;
	int		fd;
	char	*s;

	s = NULL;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("This file can not be opened", scene);
	while (get_next_line(fd, &line) > 0)
	{
		if (line == NULL)
			continue ;
		if (s == NULL)
			s = search_obj(line, scene);
		if (line)
			free(line);
	}
	close(fd);
	if (s != NULL)
		ft_error(s, scene);
	check_scene_obj(scene);
}
