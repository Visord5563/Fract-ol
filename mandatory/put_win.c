/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:17:27 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/26 07:48:22 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	map(double x, double out_max, double out_min, double j)
{
	return (x * (out_max - out_min) / j + out_min);
}

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	double	zoom_f;

	(void)x;
	(void)y;
	mlx_clear_window(img->mlx, img->win);
	zoom_f = 0.1;
	if (keycode == 5)
		img->zoom /= (1 + zoom_f);
	else if (keycode == 4)
		img->zoom *= (1 + zoom_f);
	handel_pixl(img);
	return (0);
}

void	put_pixl(t_data *img, double x, double y)
{
	while (((img->z * img->z) + (img->z1 * img->z1) <= 4)
		&& (++img->iteration < 100))
	{
		img->xtemp = ((img->z * img->z) - (img->z1 * img->z1)) + img->a;
		img->z1 = (2 * img->z * img->z1) - img->b ;
		img->z = img->xtemp;
	}
	if (img->iteration == MAX_ITERATION)
	{
		img->color = color_fractal(img->iteration);
		my_mlx_pixel_put(img, x, y, (img->color));
	}
	else
	{
		img->color = color_fractal(img->iteration);
		my_mlx_pixel_put(img, x, y, img->iteration * img->color);
	}
}

void	ft_fractol(double y, double x, t_data *img)
{
	if (img->flag == 1)
	{
		img->b = map(y + img->y, 2, -2, HEIGHT) * img->zoom;
		img->a = map(x + img->x, 2, -2, WIDTH) * img->zoom;
		img->z = 0;
		img->z1 = 0;
	}
	else if (img->flag == 2)
	{
		img->z1 = map(y + img->y, 2, -2, HEIGHT) * img->zoom;
		img->z = map(x + img->x, 2, -2, WIDTH) * img->zoom;
		img->b = img->julia_y;
		img->a = img->julia_x;
	}
	img->iteration = 0;
	put_pixl(img, x, y);
}
