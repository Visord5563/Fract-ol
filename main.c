#include "header.h"

// typedef struct	s_data 
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }		t_data;	

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// double map(double x, double in_min, double in_max, double out_min, double out_max) 
// {
//   return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
// }


int	main(int ac, char **av)
{
	void	*mlx;
	void 	*win;
	t_data	img;

	(void)ac;
	mlx = mlx_init();
	win = mlx_new_window(mlx,800,800,"fract-ol");
	img.img = mlx_new_image(mlx,800,800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// double a = 0.835; 
	// double b = 0.2321;
	double x;
	double y = -1;
	// int iteration;
	// int max_iteration =100;

	while(++y < 800)
	{
		x = -1;
		while(++x < 800)
		{
			if(av[1][0] == '1')
				ft_mandelbrod(y, x, &img);
			else
				ft_julia(y, x, &img);
		}
	}
	mlx_put_image_to_window(mlx,win,img.img,0,0);
	mlx_loop(mlx);
}
