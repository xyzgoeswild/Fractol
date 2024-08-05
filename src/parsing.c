/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:41:16 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/25 05:41:17 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_arg(char *av, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(av) != ft_strlen(name))
		return (0);
	while ((av[i] || name[j]) && name[j] == av[i])
	{
		i++;
		j++;
	}
	if (i == j)
		return (1);
	return (0);
}

int	check_julia(char *av1, char *av2)
{
	if (!float_check(av1) || !float_check(av2))
		return (1);
	return (0);
}
