/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:42:16 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 16:29:12 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	close_cross(t_scene *scene)
{
	w_close(scene);
	exit(0);
}

int	w_close(t_scene *scene)
{
	if (scene->mlx_win)
		mlx_destroy_window(scene->mlx_ptr, scene->mlx_win);
	free_scene(scene);
	return (1);
}

int	reload_window(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx_ptr, scene->mlx_win,
		scene->img.ptr, 0, 0);
	return (1);
}

int	check_key(int key, t_scene *scene)
{
	if (key == 53 || key == 65307)
		close_cross(scene);
	else if (key == 65363)
		select_camera(1, scene, 0);
	else if (key == 65361)
		select_camera(-1, scene, 0);
	return (0);
}
