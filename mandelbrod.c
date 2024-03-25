/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:17:27 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/25 03:31:59 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

	
double map(double x, double in_min, double in_max, double out_min, double out_max) 
{
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

// int	key_hook(int keycode, t_data *img)
// {
// 	if(keycode == 5)
// 		img->zoom *= 0.1;
// 	else if(keycode == 4)
// 		img->zoom *= 1.1;
// 	return(0);
// }

void ft_mandelbrod(double y, double x, t_data *img)
{
	t_var var;
	
	var.b = map(y, 0, 800, -2, 2) * img->zoom;
	var.a = map(x, 0,800, -2, 2)* img->zoom;
	var.z = 0;
	var.z1 = 0;
	var.iteration = 0;
	img->zoom = 1;
	while(((var.z * var.z) + (var.z1 * var.z1) <= 4) && (++var.iteration < 100))
	{
		var.xtemp = ((var.z*var.z) - (var.z1*var.z1)) + var.a;
		var.z1 = (2* var.z * var.z1) + var.b ;
		var.z = var.xtemp;
	}
	if (var.iteration == 100)
	{
		var.color = map(var.z, var.z1, 255, 100, 255);
		my_mlx_pixel_put(img, x ,y ,var.color);
	}
	else
	{
		var.color = map(200, 0, 20, 0, 155);
		my_mlx_pixel_put(img, x ,y , var.iteration * var.color);
	}
}

void ft_julia(double y, double x, t_data *img)
{
	t_var var;
	
	var.a = 0.835;
	var.b = 0.2321;
	var.z1 = map(y, 0,800, -2, 2);
	var.z = map(x, 0, 800, -2, 2);
	var.iteration = 0;
	
	while(((var.z*var.z) + (var.z1*var.z1) <= 4) && (++var.iteration < 100))
	{
		var.xtemp = ((var.z*var.z) - (var.z1*var.z1)) - var.a;
		var.z1 = (2* var.z * var.z1) - var.b ;
		var.z = var.xtemp;
	}
	if (var.iteration == 100)
		my_mlx_pixel_put(img, x ,y ,var.iteration * 0x00000ff << 16);
	else
		my_mlx_pixel_put(img, x ,y ,var.iteration * 0xffFFFF0);
}