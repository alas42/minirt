/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_vec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:38 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 17:28:07 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec3	cross_product_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_vec3	add_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vec3	sub_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vec3	mult_vec3(float n, t_vec3 a)
{
	t_vec3	c;

	c.x = n * a.x;
	c.y = n * a.y;
	c.z = n * a.z;
	return (c);
}

float	dot_product(t_vec3 a, t_vec3 b)
{
	float	sum;

	sum = 0.0;
	sum += a.x * b.x;
	sum += a.y * b.y;
	sum += a.z * b.z;
	return (sum);
}
