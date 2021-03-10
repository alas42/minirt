/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:15:54 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 14:16:19 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	skip_comma(char c, size_t *i)
{
	if (c == ',')
	{
		*i = *i + 1;
		return (1);
	}
	else
		return (0);
}

int	is_color_null(t_color color)
{
	if (color.red < 0.0 || color.blue < 0.0 || color.green < 0.0)
		return (1);
	else
		return (0);
}

int	is_vec_null(t_vec3 vec)
{
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return (1);
	else
		return (0);
}

int	check_range_vec3(t_vec3 vec)
{
	if (vec.x >= -1.0 && vec.x <= 1.0)
		if (vec.y >= -1.0 && vec.y <= 1.0)
			if (vec.z >= -1.0 && vec.z <= 1.0)
				return (1);
	return (0);
}
