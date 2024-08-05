/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:41:14 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/25 05:41:15 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	screen_map(double unscaled_num, double new_min, double new_max,
		double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

t_complex	sum_complx(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	sqr_complx(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	ft_atof(char *str)
{
	int		i;
	double	number;
	double	divider;
	double	sign;

	number = 0.0;
	divider = 0.1;
	i = 0;
	sign = 1;
	i = space_check(str);
	sign = sign_check(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] && str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number + ((str[i] - '0') * divider);
		divider *= 0.1;
		i++;
	}
	return (number * sign);
}

int	space_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	return (i);
}
