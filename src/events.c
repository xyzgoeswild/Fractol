/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:41:05 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/25 05:41:06 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_close(t_fractal *fractol)
{
	if (!fractol)
		exit(0);
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	if (fractol->mlx_window && fractol->mlx_connection)
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	if (fractol->mlx_connection)
	{
		mlx_loop_end(fractol->mlx_connection);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
	}
	fractol = NULL;
	exit(0);
	return (0);
}

int	mouse_handler(int keycode, int x, int y, t_fractal *fractol)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		fractol->zoom_in_out *= 1.1;
	else if (keycode == 5)
		fractol->zoom_in_out /= 1.1;
	render_fractol(fractol);
	return (0);
}

int	increase_iteration(int keycode, t_fractal *fractol)
{
	if (keycode == PLUS && fractol->max_iteration < 1000)
		fractol->max_iteration += 10;
	else if (keycode == MINUS && fractol->max_iteration >= 20)
		fractol->max_iteration -= 10;
	render_fractol(fractol);
	return (0);
}

int	handle_key(int key, t_fractal *fractol)
{
	if (key == ESC)
		handle_close(fractol);
	if (key == PLUS || key == MINUS)
		increase_iteration(key, fractol);
	if (key == UP)
		fractol->y -= (0.5 * -fractol->zoom_in_out);
	if (key == DOWN)
		fractol->y += (0.5 * -fractol->zoom_in_out);
	if (key == LEFT)
		fractol->x -= (0.5 * fractol->zoom_in_out);
	if (key == RIGHT)
		fractol->x += (0.5 * fractol->zoom_in_out);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		render_fractol(fractol);
	return (0);
}
