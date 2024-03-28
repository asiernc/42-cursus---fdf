/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:25:28 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/18 17:31:03 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MENU 350

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define NUM1 18
# define NUM2 19
# define NUM3 20
# define NUM4 21
# define NUM5 23
# define NUM6 22
# define ESCAPE 53

typedef struct s_map
{
	float	x;
	float	y;
	int		z;
	float	next_x;
	float	next_y;
	int		next_z;
	int		color;
	int		height;
	int		width;
	int		space_x;
	int		space_y;
	int		zoom;
	double	angle;
	int		scale_z;
	int		***map;
}			t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_map	*map;
}			t_fdf;

// Check Map file

int		ft_check_file(char *filename, t_fdf *img);
int		get_height(char *filename);
int		get_width(char *filename);

// Draw map

void	ft_draw_map(t_fdf *img);

// KEYBOARD EVENTS

void	ft_hook_controls(t_fdf *img);
void	renew_image(t_fdf *img);
int		ft_close_win(t_fdf *img);

// MENU

void	ft_menu(t_fdf *img);

// Utils

void	ft_put_error(const char *str, int fd);
void	ft_put_pixel(t_fdf *img, int x, int y, int color);
int		rgb_to_int(unsigned int hex_value);
void	cart_to_iso(t_fdf *img, float *x, float *y, int *z);
int		my_abs(float a);
void	fill_zoom(t_fdf *img, float *x, float *y);
void	free_mem(t_fdf *img);

#endif
