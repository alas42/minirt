/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dimensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:45:19 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 11:05:25 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	ft_get_diameter(const char *s, size_t *i)
{
	float	diameter;

	diameter = 0;
	diameter = ft_atof(s, i);
	return (diameter);
}

float	ft_get_height(const char *s, size_t *i)
{
	float	height;

	height = 0;
	height = ft_atof(s, i);
	return (height);
}

float	ft_get_ratio(const char *s, size_t *i)
{
	float	ratio;

	ratio = 0;
	ratio = ft_atof(s, i);
	return (ratio);
}

int		ft_get_fov(const char *s, size_t *i)
{
	int	fov;

	fov = 0;
	fov = ft_atof(s, i);
	return (fov);
}
