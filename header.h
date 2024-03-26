/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:23:24 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/26 07:03:25 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	double	zoom;
	char	*addr;
	double	x;
	double	y;
	double	julia_x;
	double	julia_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		flag;
	// t_var	var;
}		t_data;	
typedef struct s_var
{
	int		iteration;
	double	xtemp;
	double	z;
	double	z1;
	double	a;
	double	b;
	double	color;
}		t_var;	

// # define KEYPRESS 02
// # define BUTTONPRESS 04
// # define DestroyNotify 17
// # define KEYPRESSMASK 1L << 0
// # define ButtonPressMask (1L<<2)
// # define StructureNotifyMask (1L<<17)

double	map(double x, double in_min, double in_max,
			double out_min, double out_max);
void	ft_mandelbrod(double y, double x, t_data *img);
void	ft_julia(double y, double x, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mouse_hook(int keycode, int x, int y, t_data *img);
void	ml___x(t_data *img);
void	handel_pixl(t_data *img);
int		f_exit(t_data *img);
int		apply_keys(int key, t_data *img);

#endif