/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:48:29 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 16:45:47 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		render_image(t_scene *scene)
{
	raytracing(scene);
	mlx_put_image_to_window(scene->mlx_ptr, scene->mlx_win,
		scene->img.ptr, 0, 0);
}

void		select_camera(int change, t_scene *scene, int save)
{
	t_list	*list;
	int		i;
	int		modulo;

	i = 0;
	list = scene->camera;
	scene->act_camera += change;
	modulo = scene->act_camera % ft_lstsize(scene->camera);
	if (modulo < 0)
		modulo *= -1;
	while (i < modulo && list != NULL)
	{
		list = list->next;
		i++;
	}
	scene->a_camera = *(t_camera *)list->content;
	look_at(&(scene->a_camera));
	if (save == 1)
		raytracing_bmp(scene);
	else
		render_image(scene);
}

static void	init_scene(t_scene *scene)
{
	scene->resolution.x = -1;
	scene->resolution.y = -1;
	scene->t = -1;
	scene->object = NULL;
	scene->obj = NULL;
	scene->mlx_win = NULL;
	scene->mlx_ptr = NULL;
	scene->img.addr = NULL;
	scene->img.ptr = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	scene->amblight.ratio = -1;
	scene->amblight.color = new_color(-1, -1, -1);
	scene->act_camera = 0;
}

static void	init_scene_mlx(t_scene *scene, char *name)
{
	scene->mlx_ptr = mlx_init();
	if (!(scene->mlx_ptr))
		ft_error("Initiation of mlx failed", scene);
	check_resolution(scene);
	scene->mlx_win = mlx_new_window(scene->mlx_ptr,
			scene->resolution.x, scene->resolution.y, name);
	if (!(scene->mlx_win))
		ft_error("mlx_new_window method failed", scene);
	scene->img.ptr = mlx_new_image(scene->mlx_ptr,
			scene->resolution.x, scene->resolution.y);
	if (!(scene->img.ptr))
		ft_error("mlx_new_image method failed", scene);
	scene->img.addr = mlx_get_data_addr(scene->img.ptr,
			&scene->img.bits_per_pixel, &scene->img.line_length,
			&scene->img.endian);
}

int			main(int argc, char *argv[])
{
	t_scene	*scene;

	scene = (t_scene*)malloc(sizeof(t_scene));
	if (!(scene))
		ft_error("Allocation of scene structure failed", scene);
	init_scene(scene);
	check_args(argc, argv, scene);
	parse_file(argv[1], scene);
	if (argc == 3)
		select_camera(0, scene, 1);
	else
	{
		init_scene_mlx(scene, argv[1]);
		select_camera(0, scene, 0);
		mlx_key_hook(scene->mlx_win, check_key, scene);
		mlx_hook(scene->mlx_win, 17, STRUCTURENOTIFYMASK, close_cross, scene);
		mlx_hook(scene->mlx_win, 15, VISIBILITYCHANGEMASK,
			reload_window, scene);
		mlx_loop(scene->mlx_ptr);
	}
	return (0);
}
