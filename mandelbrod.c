/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:17:27 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/24 02:03:17 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

	
double map(double x, double in_min, double in_max, double out_min, double out_max) 
{
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

void ft_mandelbrod(double y, double x, t_data *img)
{
	int iteration = 0;
	double xtemp ;
	double z = 0; 
	double z1 = 0;
	int max_iteration =100;
	double a = 0; 
	double b = 0;
	
	b = map(y, 0, 800, -2, 2);
	a = map(x, 0,800, -2, 2);
	while(((z*z) + (z1*z1) <= 4) && (++iteration < max_iteration))
	{
		xtemp = ((z*z) - (z1*z1)) + a;
		z1 = (2* z * z1) + b ;
		z = xtemp;
	}
	if (iteration == max_iteration)
		my_mlx_pixel_put(img, x ,y ,iteration * 0xFFF00cF<<16);
	else
		my_mlx_pixel_put(img, x ,y ,iteration * 0xFAF00FF);
}

void ft_julia(double y, double x, t_data *img)
{
	int iteration = 0;
	double xtemp ;
	double z = 0; 
	double z1 = 0;
	int max_iteration =100;
	double a = 0.835; 
	double b = 0.2321;
	
	z1 = map(y, 0, 800, -2, 2);
	z = map(x, 0,800, -2, 2);
	while(((z*z) + (z1*z1) <= 4) && (++iteration < max_iteration))
	{
		xtemp = ((z*z) - (z1*z1)) - a;
		z1 = (2* z * z1) - b ;
		z = xtemp;
	}
	if (iteration == max_iteration)
		my_mlx_pixel_put(img, x ,y ,iteration * 0x00000<<16);
	else
		my_mlx_pixel_put(img, x ,y ,iteration * 0xff00000);
}