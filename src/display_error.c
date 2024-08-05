/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:41:03 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/25 05:41:04 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	display_error(int fd)
{
	write(fd, RED "Invalid: ./fractol [fractal] (Optional [X] [Y] for Julia)\n",
		66);
	exit(EXIT_FAILURE);
}
