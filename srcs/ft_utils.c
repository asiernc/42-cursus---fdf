/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:06:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/18 16:37:31 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_error(const char *err_msg, int fd)
{
	if (fd)
		ft_putendl_fd(err_msg, fd);
	else
		perror(err_msg);
	exit(-1);
}

int	rgb_to_int(unsigned int hex_value)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = (hex_value >> 16 & 0xFF) / 255.0;
	g = (hex_value >> 8 & 0xFF) / 255.0;
	b = (hex_value & 0xFF) / 255.0;
	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	ft_put_pixel(t_fdf *img, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * img->bpp / 8) + (y * img->line_length);
		img->addr[i] = color;
		img->addr[++i] = (color >> 8);
		img->addr[++i] = (color >> 16);
	}
}

void	fill_zoom(t_fdf *img, float *x, float *y)
{
	*x *= img->map->zoom;
	*y *= img->map->zoom;
	img->map->next_x *= img->map->zoom;
	img->map->next_y *= img->map->zoom;
}

int	my_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}
