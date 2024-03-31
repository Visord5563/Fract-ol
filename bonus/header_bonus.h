/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:23:24 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/31 02:02:06 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
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
	double	x_max;
	double	y_max;
	double	x_min;
	double	y_min;
	double	p_m;
	double	julia_x;
	double	julia_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		flag;
	int		iteration;
	double	xtemp;
	double	z;
	double	z1;
	double	a;
	double	b;
	double	color;
}		t_data;	

# define COLOR_RED    0xFF0000
# define COLOR_GREEN  0x00FF00
# define COLOR_BLUE   0x0000FF
# define COLOR_WHITE  0xFFFFFF
# define COLOR_BLACK  0x000000
# define COLOR_YELLOW 0xFFFF00
# define COLOR_CYAN   0x00FFFF
# define COLOR_MAGENTA 0xFF00FF
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATION 100

double	map(double x, double out_max, double out_min);
void	ft_fractol(t_data *img, double x, double y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mouse_hook(int keycode, int x, int y, t_data *img);
void	ml___x(t_data *img);
void	handel_pixl(t_data *img);
int		f_exit(t_data *img);
int		apply_keys(int key, t_data *img);
int		color_fractal(int iteration);
void	put_pixl(t_data *img, double x, double y);
int		parssing(t_data *img, int ac, char **av);
size_t	ft_sln(const char *s);
double	ft_atof(char *str);
int		ft_sncm(const char *s1, const char *s2, size_t n);
void	in_im(t_data *img);

#endif