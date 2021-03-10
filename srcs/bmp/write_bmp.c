/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:17:37 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 12:27:46 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	free_tab_pixels(t_pixel **pixels, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->resolution.y)
	{
		free(pixels[i]);
		i++;
	}
	free(pixels);
}

static void	generate_header(unsigned char *header, int width, int height)
{
	int	pix_in_row;
	int	padd_in_row;

	pix_in_row = width * sizeof(t_pixel);
	padd_in_row = (4 - (pix_in_row % 4)) % 4;
	ft_memset(header, 0, 54);
	header[0] = 'B';
	header[1] = 'M';
	header[2] = 54 + (pix_in_row + padd_in_row) * height;
	header[10] = PIXEL_DATA_OFFSET;
	header[14] = INFO_HEADER_SIZE;
	*(int *)(&header[18]) = width;
	*(int *)(&header[22]) = height;
	header[26] = 1;
	header[28] = BITS_PER_PIXEL;
}

static void	write_in_file(int width, int height, t_pixel **pixels, int fd)
{
	int		pix_in_row;
	int		padd_in_row;
	int		row;
	char	rest[3];

	rest[0] = '0';
	rest[1] = '0';
	rest[2] = '0';
	pix_in_row = width * sizeof(t_pixel);
	padd_in_row = (4 - (pix_in_row % 4)) % 4;
	row = height - 1;
	while (row >= 0)
	{
		write(fd, pixels[row], pix_in_row);
		write(fd, rest, padd_in_row);
		row--;
	}
}

void		save_in_bmp(t_scene *scene, t_pixel **pixels)
{
	int				fd;
	unsigned char	header[54];

	generate_header(header, scene->resolution.x, scene->resolution.y);
	fd = open("image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		free_tab_pixels(pixels, scene);
		ft_error("file.bmp can not be opened", scene);
	}
	write(fd, header, 54);
	write_in_file(scene->resolution.x, scene->resolution.y, pixels, fd);
	close(fd);
	free_tab_pixels(pixels, scene);
	w_close(scene);
	exit(0);
}
