/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:29:23 by asiercara         #+#    #+#             */
/*   Updated: 2024/03/18 16:37:40 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_instructions(t_fdf *img)
{
	mlx_string_put(img->mlx, img->win, 20, 70, 0xffffff,
		"Press '<' to move left.");
	mlx_string_put(img->mlx, img->win, 20, 90, 0xffffff,
		"Press '>' to move right");
	mlx_string_put(img->mlx, img->win, 20, 110, 0xffffff,
		"Press '^' to move up.");
	mlx_string_put(img->mlx, img->win, 20, 130, 0xffffff,
		"Press 'v' to move down.");
	mlx_string_put(img->mlx, img->win, 20, 150, 0xffffff,
		"Press '1' to zoom out.");
	mlx_string_put(img->mlx, img->win, 20, 170, 0xffffff,
		"Press '2' to zoom in.");
	mlx_string_put(img->mlx, img->win, 20, 190, 0xffffff,
		"Press '3' to decrease altitude.");
	mlx_string_put(img->mlx, img->win, 20, 210, 0xffffff,
		"Press '4' to increase altitude.");
	mlx_string_put(img->mlx, img->win, 20, 230, 0xffffff,
		"Press '5' to rotate left.");
	mlx_string_put(img->mlx, img->win, 20, 250, 0xffffff,
		"Press '6' to rotate rigth.");
}

static void	ft_values_aux(t_fdf *img)
{
	char	*val;
	int		dec;

	dec = img->map->angle * 100;
	if (dec > 110)
		dec -= 100;
	mlx_string_put(img->mlx, img->win, 20, 370, 0xffffff,
		"Angle value: ");
	mlx_string_put(img->mlx, img->win, 145, 370, 0xffffff,
		val = ft_itoa(img->map->angle));
	free(val);
	mlx_string_put(img->mlx, img->win, 160, 370, 0xffffff,
		".");
	mlx_string_put(img->mlx, img->win, 175, 370, 0xffffff,
		val = ft_itoa(dec));
	free(val);
	val = NULL;
}

static void	ft_values(t_fdf *img)
{
	char	*val;

	mlx_string_put(img->mlx, img->win, 20, 310, 0xffffff,
		"Coords: (");
	mlx_string_put(img->mlx, img->win, 110, 310, 0xffffff,
		val = ft_itoa(img->map->space_x));
	free(val);
	mlx_string_put(img->mlx, img->win, 150, 310, 0xffffff,
		", ");
	mlx_string_put(img->mlx, img->win, 165, 310, 0xffffff,
		val = ft_itoa(img->map->space_y));
	free(val);
	mlx_string_put(img->mlx, img->win, 195, 310, 0xffffff,
		")");
	mlx_string_put(img->mlx, img->win, 20, 330, 0xffffff,
		"Zoom value: ");
	mlx_string_put(img->mlx, img->win, 140, 330, 0xffffff,
		val = ft_itoa(img->map->zoom));
	free(val);
	mlx_string_put(img->mlx, img->win, 20, 350, 0xffffff,
		"Altitude scale: ");
	mlx_string_put(img->mlx, img->win, 180, 350, 0xffffff,
		val = ft_itoa(img->map->scale_z));
	free(val);
	ft_values_aux(img);
}

void	ft_menu(t_fdf *img)
{
	mlx_string_put(img->mlx, img->win, 100, 20, 0x00b5ff, "INSTRUCTIONS");
	mlx_string_put(img->mlx, img->win, 10, 45, 0x0037ff, "Controls");
	ft_instructions(img);
	mlx_string_put(img->mlx, img->win, 10, 280, 0x0037ff, "Values");
	ft_values(img);
}
