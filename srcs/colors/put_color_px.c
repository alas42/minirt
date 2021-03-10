/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:17:19 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 17:16:55 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	put_color_px(t_image *image, int x, int y, t_color color)
{
	int	i;

	i = y * image->line_length + image->bits_per_pixel / 8 * x;
	image->addr[i] = (int)(fmin(1.0, color.blue) * 255);
	image->addr[i + 1] = (int)(fmin(1.0, color.green) * 255);
	image->addr[i + 2] = (int)(fmin(1.0, color.red) * 255);
}
