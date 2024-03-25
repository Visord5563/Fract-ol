#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ml___x(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx,800,800,"fract-ol");
	img->img = mlx_new_image(img->mlx,800,800);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void handel_pixl(t_data *img, char **av)
{
	double x;
	double y = -1;
	int i = strlen(av[1]);

	while(++y < 800)
	{
		x = -1;
		while(++x < 800)
		{
			if(i == 10 && strcmp(av[1], "mandeldrod") == 0)
				ft_mandelbrod(y, x, img);
			else if(i == 5 && strcmp(av[1], "julia") == 0)
					ft_julia(y, x, img);
			else
			{
				write(1, "uncorect name", 13);
				exit(0);
			}
		}
	}
}

int	main(int ac, char **av)
{
	t_data	img;

	if(ac != 2)
		return (1);
	ml___x(&img);
	handel_pixl(&img, av);
	// mlx_mouse_hook(img.win, key_hook, &img);
	mlx_put_image_to_window(img.mlx,img.win,img.img,0,0);
	mlx_loop(img.mlx);
}
