/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:45:08 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 17:22:27 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	check_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len > 3)
		if (filename[len - 3] == '.' && filename[len - 2] == 'r'
			&& filename[len - 1] == 't')
			return (1);
	return (-1);
}

void		check_args(int ac, char *av[], t_scene *scene)
{
	if (ac < 2 || ac > 3)
		ft_error("Number of arguments is incorrect", scene);
	if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		ft_error("Argument 3 incorrect : (use --save)", scene);
	if (check_filename(av[1]) == -1)
		ft_error("Scenes files must end with .rt", scene);
}

void		check_resolution(t_scene *scene)
{
	int	sizex;
	int	sizey;

	sizex = 1;
	sizey = 1;
	mlx_get_screen_size(scene->mlx_ptr, &sizex, &sizey);
	if (scene->resolution.x > sizex)
		scene->resolution.x = sizex;
	if (scene->resolution.y > sizey)
		scene->resolution.y = sizey;
}
