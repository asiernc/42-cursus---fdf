/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:59:41 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/18 16:38:00 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *filename)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(filename, O_RDONLY, 0400);
	if (fd == -1)
		ft_put_error("Open file error.", fd);
	height = 0;
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_put_error("Close file error.", fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;
	int		i;

	fd = open(filename, O_RDONLY, 0400);
	if (fd == -1)
		ft_put_error("Open file error.", fd);
	i = -1;
	width = 0;
	get_next_line(fd, &line);
	if ((*line) == '\0')
		ft_put_error("Empty map.", fd);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	if (close(fd) == -1)
		ft_put_error("Close file error", fd);
	return (width);
}

static void	ft_fill_matrix(int **height, char *line)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	i = -1;
	while (num[++i])
	{
		height[i] = malloc(2 * sizeof(int));
		if (!height[i])
			ft_put_error("Malloc error", 2);
		height[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			height[i][1] = (rgb_to_int(ft_atoi_base(&num[i][++j],
							"0123456789ABCDEF")));
		else
			height[i][1] = 16777215;
		free(num[i]);
	}
	free(num);
}

int	ft_check_file(char *filename, t_fdf *img)
{
	int		fd;
	int		i;
	char	*line;

	img->map->height = get_height(filename);
	img->map->width = get_width(filename);
	fd = open(filename, O_RDONLY, 0400);
	if (fd == -1)
		ft_put_error("Open file error.", fd);
	img->map->map = malloc(img->map->height * sizeof(int **));
	if (!img->map->map)
		ft_put_error("Memory allocation error.", 2);
	i = -1;
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		img->map->map[++i] = malloc(img->map->width * sizeof(int *));
		if (!img->map->map[i])
			ft_put_error("malloc error", 1);
		ft_fill_matrix(img->map->map[i], line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
