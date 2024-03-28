/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:01:03 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/18 16:36:52 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	fill_values(t_fdf *img, int x, int y)
{
	img->map->z = img->map->map[y][x][0];
	img->map->color = img->map->map[y][x][1];
	img->map->next_z = img->map->map[(int)img->map->next_y]
	[(int)img->map->next_x][0];
	if (img->map->z)
		img->map->z *= img->map->scale_z;
	if (img->map->next_z)
		img->map->next_z *= img->map->scale_z;
}

static void	apply_margins(t_fdf *img, float *x, float *y)
{
	*x += img->map->space_x;
	*y += img->map->space_y;
	img->map->next_x += img->map->space_x;
	img->map->next_y += img->map->space_y;
}

static void	draw_line(t_fdf *img, float x, float y)
{
	float	end_x;
	float	end_y;
	int		steps;

	fill_values(img, (int)x, (int)y);
	fill_zoom(img, &x, &y);
	cart_to_iso(img, &x, &y, &img->map->z);
	cart_to_iso(img, &img->map->next_x, &img->map->next_y, &img->map->next_z);
	apply_margins(img, &x, &y);
	end_x = img->map->next_x - x;
	end_y = img->map->next_y - y;
	steps = fmax(my_abs(end_x), my_abs(end_y));
	end_x /= steps;
	end_y /= steps;
	while (steps--)
	{
		if (x < MENU || y < 0 || x > WIDTH || y > HEIGHT)
			break ;
		ft_put_pixel(img, x, y, img->map->color);
		x += end_x;
		y += end_y;
	}
}

void	ft_draw_map(t_fdf *img)
{
	int		x;
	int		y;

	y = -1;
	while (++y < img->map->height)
	{
		x = -1;
		while (++x < img->map->width)
		{
			img->map->next_x = x;
			img->map->next_y = y + 1;
			if (y < img->map->height - 1)
				draw_line(img, x, y);
			img->map->next_x = x + 1;
			img->map->next_y = y;
			if (x < img->map->width - 1)
				draw_line(img, x, y);
		}
	}
}
