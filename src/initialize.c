/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:41:08 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/25 05:41:09 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	malloc_error(void)
{
	write(1, RED "Issues with malloc :(\n", 30);
	exit(EXIT_FAILURE);
}

void	init_event(t_fractal *fractol)
{
	mlx_key_hook(fractol->mlx_window, &handle_key, fractol);
	mlx_mouse_hook(fractol->mlx_window, mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, 17, 1, handle_close, fractol);
}

void	init_data(t_fractal *fractol)
{
	fractol->escape_value = 4;
	fractol->zoom_in_out = 1.0;
	fractol->x = 0;
	fractol->y = 0;
	fractol->max_iteration = 50;
}

void	fractol_init(t_fractal *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT,
			fractol->title);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH,
			HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.pixel_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	init_event(fractol);
	init_data(fractol);
}
