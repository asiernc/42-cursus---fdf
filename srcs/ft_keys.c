/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:33:51 by asiercara         #+#    #+#             */
/*   Updated: 2024/03/19 11:15:19 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_translate(int keycode, t_fdf *img)
{
	if (keycode == ARROW_LEFT)
		img->map->space_x -= 10;
	else if (keycode == ARROW_RIGHT)
		img->map->space_x += 10;
	else if (keycode == ARROW_DOWN)
		img->map->space_y += 10;
	else if (keycode == ARROW_UP)
		img->map->space_y -= 10;
}

static void	ft_zoom_or_rotate(int keycode, t_fdf *img)
{
	if (keycode == NUM1)
		img->map->zoom -= 2;
	else if (keycode == NUM2)
		img->map->zoom += 2;
	if (keycode == NUM5)
		img->map->angle -= 0.1;
	else if (keycode == NUM6)
		img->map->angle += 0.1;
}

static void	ft_mod_height(int keycode, t_fdf *img)
{
	if (keycode == NUM3)
		img->map->scale_z -= 1;
	else if (keycode == NUM4)
		img->map->scale_z += 1;
	if (img->map->scale_z < 1)
		img->map->scale_z = 1;
	else if (img->map->scale_z > 10)
		img->map->scale_z = 10;
}

static int	ft_key_hook(int keycode, t_fdf *img)
{
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_DOWN || keycode == ARROW_UP)
		ft_translate(keycode, img);
	else if (keycode == NUM1 || keycode == NUM2
		|| keycode == NUM5 || keycode == NUM6)
		ft_zoom_or_rotate(keycode, img);
	else if (keycode == NUM3 || keycode == NUM4)
		ft_mod_height(keycode, img);
	else if (keycode == ESCAPE)
	{
		mlx_destroy_window(img->mlx, img->win);
		free_mem(img);
		exit(0);
	}
	renew_image(img);
	ft_draw_map(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	ft_menu(img);
	return (0);
}

void	ft_hook_controls(t_fdf *img)
{
	mlx_hook(img->win, 2, 0, ft_key_hook, img);
	mlx_hook(img->win, 17, 0, ft_close_win, img);
}
