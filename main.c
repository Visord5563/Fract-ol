#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;	

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double map(double x, double in_min, double in_max, double out_min, double out_max) 
{
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}


int	main(void)
{
	void	*mlx;
	void 	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx,800,800,"fract-ol");
	img.img = mlx_new_image(mlx,800,800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	double a; 
	double b;
	double xs;
	double ys = -1;
	int iteration;
	int max_iteration =100;

	while(++ys < 800)
	{
		xs = -1;
		while(++xs < 800)
		{
			iteration = 0;
			double xtemp ;
			double x =0; 
			double y =0;
			b = map(ys, 0, 800, -2, 2);
			a = map(xs, 0,800, -2, 2);
			while(((x*x) + (y*y) <= 4) && (++iteration < max_iteration))
			{
				xtemp = ((x*x) - (y*y)) + a;
				y = (2* x * y) - b;
				x = xtemp;
			}
		if (iteration == max_iteration)
			my_mlx_pixel_put(&img, xs ,ys , 0x000000000);
		else
			my_mlx_pixel_put(&img, xs ,ys , 0xFFFFFFF);
		}
	}
	mlx_put_image_to_window(mlx,win,img.img,0,0);
	mlx_loop(mlx);
}
