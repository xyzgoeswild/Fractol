/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:41:19 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/25 05:41:20 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (check_arg(fractal->title, "julia"))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	handle_pxl(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (screen_map(x, -2, +2, WIDTH) * fractal->zoom_in_out) + fractal->x;
	z.y = (screen_map(y, +2, -2, HEIGHT) * fractal->zoom_in_out) + fractal->y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->max_iteration)
	{
		z = sum_complx(sqr_complx(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = screen_map(i, BLACK, LIME_SHOCK, fractal->max_iteration);
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	put_pixel(x, y, &fractal->img, BLACK);
}

void	render_fractol(t_fractal *fractol)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pxl(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
