/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:23:24 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/24 01:59:45 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;	

double map(double x, double in_min, double in_max, double out_min, double out_max);
void ft_mandelbrod(double y, double x, t_data *img);
void ft_julia(double y, double x, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif