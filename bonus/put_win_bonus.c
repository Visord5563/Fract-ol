/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_win_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:43:53 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/31 03:33:57 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

double	map(double x, double out_max, double out_min)
{
	return ((x - 0) * (out_max - out_min) / WIDTH + out_min);
}

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = (img->x_min - img->x_max) / 800;
	zoom_y = (img->y_min - img->y_max) / 800;
	if (keycode == 5)
	{
		img->x_min += (x * zoom_x) * 0.1;
		img->x_max -= ((800 - x) * zoom_x) * 0.1;
		img->y_min += (y * zoom_y) * 0.1;
		img->y_max -= ((800 - y) * zoom_y) * 0.1;
	}
	else if (keycode == 4)
	{
		img->x_min -= (x * zoom_x) * 0.1;
		img->x_max += ((800 - x) * zoom_x) * 0.1;
		img->y_min -= (y * zoom_y) * 0.1;
		img->y_max += ((800 - y) * zoom_y) * 0.1;
	}
	mlx_clear_window(img->mlx, img->win);
	handel_pixl(img);
	return (0);
}

double	ft_abs(double n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	put_pixl(t_data *img, double x, double y)
{
	while (((img->z * img->z) + (img->z1 * img->z1) <= 4)
		&& (++img->iteration < 100))
	{
		img->xtemp = ((img->z * img->z) - (img->z1 * img->z1)) + img->a;
		if (img->flag == 0)
			img->z1 = ft_abs(2 * img->z * img->z1) + img->b;
		else
			img->z1 = (2 * img->z * img->z1) - img->b;
		img->z = img->xtemp;
	}
	if (img->iteration == MAX_ITERATION)
	{
		img->color = color_fractal(img->iteration);
		my_mlx_pixel_put(img, x, y, (img->color));
	}
	else
	{
		img->color = (color_fractal(img->iteration) + img->p_m);
		my_mlx_pixel_put(img, x, y, img->color * img->iteration);
	}
}

void	ft_fractol(t_data *img, double x, double y)
{
	if (img->flag == 1 || img->flag == 0)
	{
		img->b = map(y + img->y, img->y_max, img->y_min);
		img->a = map(x + img->x, img->x_max, img->x_min);
		img->z = 0;
		img->z1 = 0;
	}
	else if (img->flag == 2)
	{
		img->z1 = map(y + img->y, img->y_max, img->y_min);
		img->z = map(x + img->x, img->x_max, img->x_min);
		img->b = img->julia_y;
		img->a = img->julia_x;
	}
	img->iteration = 0;
	put_pixl(img, x, y);
}
