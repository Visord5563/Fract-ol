/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:17:27 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/26 07:02:17 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	map(double x, double in_min, double in_max, double out_min, double out_max) 
{
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	double	zoom_f;

	(void)x;
	(void)y;
	zoom_f = 0.1;
	if (keycode == 5)
		img->zoom /= (1 + zoom_f);
	else if (keycode == 4)
		img->zoom *= (1 + zoom_f);
	handel_pixl(img);
	return (0);
}

void	ft_mandelbrod(double y, double x, t_data *img)
{
	t_var	var;

	if (img->flag == 1)
	{
		var.b = map(y + img->y, 0, 800, -2, 2) * img->zoom;
		var.a = map(x + img->x, 0, 800, -2, 2) * img->zoom;
		var.z = 0;
		var.z1 = 0;
	}
	else if (img->flag == 2)
	{
		var.z1 = map(y + img->y, 0, 800, -2, 2) * img->zoom;
		var.z = map(x + img->x, 0, 800, -2, 2) * img->zoom;
		var.b = img->julia_y;
		var.a = img->julia_x;
	}
	var.iteration = 0;
	while (((var.z * var.z) + (var.z1 * var.z1) <= 4) && (++var.iteration < 100))
	{
		var.xtemp = ((var.z * var.z) - (var.z1 * var.z1)) + var.a;
		var.z1 = (2 * var.z * var.z1) - var.b ;
		var.z = var.xtemp;
	}
	if (var.iteration == 100)
	{
		var.color = map(var.z, var.z1, 255, 100, 255);
		my_mlx_pixel_put(img, x, y, var.color);
	}
	else
	{
		var.color = map(200, 0, 20, 0, 155);
		my_mlx_pixel_put(img, x, y, var.iteration * var.color);
	}
}
