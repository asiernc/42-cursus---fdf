/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:59:47 by asiercara         #+#    #+#             */
/*   Updated: 2024/03/19 11:17:42 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	renew_image(t_fdf *img)
{
	free(img->img);
	free(img->addr);
	img->img = mlx_new_image(img->win, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
}

void	cart_to_iso(t_fdf *img, float *x, float *y, int *z)
{
	*x = (*x - *y) * cos(img->map->angle);
	*y = (*x + *y) * sin(img->map->angle) - *z;
}

int	ft_close_win(t_fdf *img)
{
	mlx_destroy_window(img->mlx, img->win);
	free_mem(img);
	exit(0);
	return (0);
}

void	free_mem(t_fdf *img)
{
	int	y;
	int	x;

	y = -1;
	while (++y < img->map->height)
	{
		x = -1;
		while (++x < img->map->width)
			free(img->map->map[y][x]);
		free(img->map->map[y]);
	}
}
