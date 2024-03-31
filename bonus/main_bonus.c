/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 06:51:43 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/31 01:55:41 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ml___x(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 800, 800, "fract-ol");
	img->img = mlx_new_image(img->mlx, 800, 800);
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
	mlx_clear_window(img->mlx, img->win);
	if (key == 126)
		img->y += 10;
	else if (key == 123)
		img->x += 10;
	else if (key == 125)
		img->y -= 10;
	else if (key == 124)
		img->x -= 10;
	if (key == 69)
		img->p_m += 1;
	else if (key == 78)
		img->p_m -= 1;
	if (key == 53)
		f_exit(img);
	handel_pixl(img);
	return (0);
}

void	in_im(t_data *img)
{
	img->x = -1;
	img->y = -1;
	img->p_m = 0;
	img->x_max = 2;
	img->x_min = -2;
	img->y_max = 2;
	img->y_min = -2;
	if (img->flag != 2)
	{
		img->julia_x = 0;
		img->julia_y = 0;
	}
}

int	main(int ac, char **av)
{
	t_data	img;

	if (parssing(&img, ac, av) == 1)
		return (1);
	ml___x(&img);
	in_im(&img);
	mlx_hook(img.win, 02, (1L << 0), apply_keys, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	handel_pixl(&img);
	mlx_hook(img.win, 17, 0, f_exit, &img);
	mlx_loop(img.mlx);
}
