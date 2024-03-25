/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:23:24 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/25 03:26:25 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_data 
{
	void	*mlx;
	void 	*win;
	void	*img;
	double  zoom;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;	
typedef struct	s_var 
{
	int iteration;
	double xtemp;
	double z; 
	double z1;
	double a; 
	double b;
	double color;
}		t_var;	

double map(double x, double in_min, double in_max, double out_min, double out_max);
void ft_mandelbrod(double y, double x, t_data *img);
void ft_julia(double y, double x, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	key_hook(int keycode, t_data *img);
void ml___x(t_data *img);

#endif