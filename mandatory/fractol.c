/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 07:57:39 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/30 05:19:22 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_sncm(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((d1[i] == d2[i]) && (d1[i] != '\0' && d2[i] != '\0') && i < n - 1)
		i++;
	return (d1[i] - d2[i]);
}

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
	if (ac == 2 && ft_sln(av[1]) == 10 && ft_sncm(av[1], "mandelbrot", 10) == 0)
		img->flag = 1;
	else if ((ac == 4 || ac == 2)
		&& ft_sln(av[1]) == 5 && ft_sncm(av[1], "julia", 5) == 0)
	{
		if (ac == 4)
		{
			img->julia_x = ft_atof(av[2]);
			img->julia_y = ft_atof(av[3]);
		}
		else
		{
			img->julia_x = 0;
			img->julia_y = 0;
		}
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
