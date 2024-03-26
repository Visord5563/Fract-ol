/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 07:57:39 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/26 08:31:32 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handel_pixl(t_data *img)
{
	double	x;
	double	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_fractol(y, x, img);
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (data->addr) + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color_fractal(int iteration)
{
	int	red;
	int	green;
	int	blue;

	if (iteration == MAX_ITERATION)
		return (0x000000);
	else
	{
		red = (iteration * 255) / 200;
		green = (iteration * 255) / 200;
		blue = (iteration * 255) / 50;
		return ((red << 16) | (green << 8) | blue);
	}
}

int	parssing(t_data *img, int ac, char **av)
{
	if (ac == 2 && strlen(av[1]) == 10 && strncmp(av[1], "mandelbrot", 10) == 0)
		img->flag = 1;
	else if (ac == 4 && strlen(av[1]) == 5 && strncmp(av[1], "julia", 5) == 0)
	{
		img->julia_x = atof(av[2]);
		img->julia_y = atof(av[3]);
		img->flag = 2;
	}
	else
	{
		write(1, "2 arguments must be passed enter\n", 34);
		write(1, "\t\"mandelbrot\" \nor\n \t\"julia\"\n", 29);
		return (1);
	}
	return (0);
}
