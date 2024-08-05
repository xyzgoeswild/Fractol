/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:41:11 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/25 05:41:12 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractol;

	if ((ac == 2 && check_arg(av[1], "mandelbrot")))
	{
		fractol.title = av[1];
		fractol_init(&fractol);
		render_fractol(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else if ((ac == 4 && check_arg(av[1], "julia")) && !check_julia(av[2],
			av[3]))
	{
		fractol.title = av[1];
		fractol.julia_x = ft_atof(av[2]);
		fractol.julia_y = ft_atof(av[3]);
		fractol_init(&fractol);
		render_fractol(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		display_error(STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (0);
}
