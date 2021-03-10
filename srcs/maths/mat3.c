/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:24 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:10:26 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec3			mult_mat3_vec3(t_mat3 mat, t_vec3 vec)
{
	t_vec3	result;
	t_mat3	transpo;

	transpo.v1.x = mat.v1.x;
	transpo.v1.y = mat.v2.x;
	transpo.v1.z = mat.v3.x;
	transpo.v2.x = mat.v1.y;
	transpo.v2.y = mat.v2.y;
	transpo.v2.z = mat.v3.y;
	transpo.v3.x = mat.v1.z;
	transpo.v3.y = mat.v2.z;
	transpo.v3.z = mat.v3.z;
	result.x = dot_product(transpo.v1, vec);
	result.y = dot_product(transpo.v2, vec);
	result.z = dot_product(transpo.v3, vec);
	return (result);
}

static t_mat3	invert_mat3(t_mat3 mat)
{
	t_mat3	new;
	t_vec3	new_dir[3];

	new_dir[0] = create_vec3(mat.v1.x, mat.v2.x, mat.v3.x);
	new_dir[1] = create_vec3(mat.v1.y, mat.v2.y, mat.v3.y);
	new_dir[2] = create_vec3(mat.v1.z, mat.v2.z, mat.v3.z);
	new_dir[0] = mult_vec3(1 / (pow(sqrt(dot_product(new_dir[0],
							new_dir[0])), 2)), new_dir[0]);
	new_dir[1] = mult_vec3(1 / (pow(sqrt(dot_product(new_dir[1],
							new_dir[1])), 2)), new_dir[1]);
	new_dir[2] = mult_vec3(1 / (pow(sqrt(dot_product(new_dir[2],
							new_dir[2])), 2)), new_dir[2]);
	new.v1 = new_dir[0];
	new.v2 = new_dir[1];
	new.v3 = new_dir[2];
	return (new);
}

void			look_at(t_camera *cam)
{
	t_vec3	basic;
	t_mat3	tmp;
	t_vec3	dir[3];

	basic = create_vec3(0.0, 1.0, 0.0);
	dir[2] = cam->vec;
	if (dir[2].y == 1.0)
		dir[0] = create_vec3(1.0, 0.0, 0.0);
	else if (dir[2].y == -1.0)
		dir[0] = create_vec3(-1.0, 0.0, 0.0);
	else
		dir[0] = cross_product_vec3(basic, dir[2]);
	dir[1] = cross_product_vec3(dir[2], dir[0]);
	tmp.v1 = create_vec3(dir[0].x, dir[0].y, dir[0].z);
	tmp.v2 = create_vec3(dir[1].x, dir[1].y, dir[1].z);
	tmp.v3 = create_vec3(dir[2].x, dir[2].y, dir[2].z);
	cam->cam_w = invert_mat3(tmp);
}

t_mat3			new_mat3(void)
{
	t_mat3	new;

	new.v1 = create_vec3(1, 0, 0);
	new.v2 = create_vec3(0, 1, 0);
	new.v3 = create_vec3(0, 0, 1);
	return (new);
}
