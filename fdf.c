/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/19 11:17:38 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_window(char *path, t_fdf *img)
{
	char	*title;

	title = ft_strjoin("FDF ANOVIO-C - ", path);
	img->mlx = mlx_init();
	if (!img->mlx)
		ft_put_error("Error establishing a connection to the graphics system.",
			2);
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, title);
	if (!img->win)
		ft_put_error("Error initializing window.", 2);
	free(title);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (!img->img)
		ft_put_error("error initializing image", 2);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
}

static void	ft_init_map(t_fdf *img)
{
	img->map->space_x = (WIDTH - MENU) / 3 + MENU;
	img->map->space_y = HEIGHT / 3;
	img->map->angle = 0.6;
	img->map->zoom = fmin(WIDTH / img->map->width / 2,
			HEIGHT / img->map->height / 2);
	img->map->scale_z = 1;
}

int	main(int argc, char **argv)
{
	t_fdf	img;

	if (argc != 2)
		return (0);
	ft_init_window(argv[1], &img);
	img.map = malloc(sizeof(t_map));
	if (!img.map)
		ft_put_error("Memory allocation error.", 1);
	ft_check_file(argv[1], &img);
	ft_init_map(&img);
	ft_draw_map(&img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	ft_menu(&img);
	ft_hook_controls(&img);
	mlx_loop(img.mlx);
	return (0);
}
/*static void	print_int_array(s_map *map)
{
	printf("Alturas de la matriz:\n");
	for (int i = 0; i < map->height; i++)
	{
		printf("Fila %d:\n\t", i + 1);
		for (int j = 0; j < map->width; j++)
		{
			printf("(%d, %X) ", map->map[i][j][0], map->map[i][j][1]);
		}
		printf("\n");
	}
}*/
