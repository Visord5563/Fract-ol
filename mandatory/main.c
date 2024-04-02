/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 06:51:43 by saharchi          #+#    #+#             */
/*   Updated: 2024/04/02 08:46:42 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ml___x(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "fract-ol");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	f_exit(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit (0);
	return (0);
}

int	apply_keys(int key, t_data *img)
{
	if (key == 53)
		f_exit(img);
	mlx_clear_window(img->mlx, img->win);
	handel_pixl(img);
	return (0);
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

	parssing(&img, ac, av);
	ml___x(&img);
	in_im(&img);
	mlx_key_hook(img.win, apply_keys, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	handel_pixl(&img);
	mlx_hook(img.win, 17, 0, f_exit, &img);
	mlx_loop(img.mlx);
}
