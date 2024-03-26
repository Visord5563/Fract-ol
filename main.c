/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 06:51:43 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/26 06:58:16 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (data->addr) + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ml___x(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 800, 800, "fract-ol");
	img->img = mlx_new_image(img->mlx, 800, 800);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

int	f_exit(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit (0);
	return (0);
}

int	apply_keys(int key, t_data *img)
{
	if (key == 126)
		img->y += 10;
	else if (key == 123)
		img->x += 10;
	else if (key == 125)
		img->y -= 10;
	else if (key == 124)
		img->x -= 10;
	if (key == 53)
		f_exit(img);
	handel_pixl(img);
	return (0);
}

void	handel_pixl(t_data *img)
{
	double	x;
	double	y;

	y = -1;
	while (++y < 800)
	{
		x = -1;
		while (++x < 800)
			ft_mandelbrod(y, x, img);
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	in_im(t_data *img)
{
	img->zoom = 1;
	img->x = -1;
	img->y = -1;
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac == 2 && strlen(av[1]) == 10 && strncmp(av[1], "mandelbrot", 10) == 0)
		img.flag = 1;
	else if (ac == 4 && strlen(av[1]) == 5 && strncmp(av[1], "julia", 5) == 0)
	{
		img.julia_x = atof(av[2]);
		img.julia_y = atof(av[3]);
		img.flag = 2;
	}
	else
	{
		write(1, "2 arguments must be passed enter\n\t\"mandelbrot\" \nor\n \t\"julia\"\n", 63);
		return (1);
	}
	ml___x(&img);
	in_im(&img);
	mlx_key_hook(img.win, apply_keys, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	handel_pixl(&img);
	mlx_hook(img.win, 17, 0, f_exit, &img);
	mlx_loop(img.mlx);
}
