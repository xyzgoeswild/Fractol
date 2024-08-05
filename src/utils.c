/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:41:22 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/25 05:41:23 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_isdigit(int c)
{
	while (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	trailing_spaces(char *str, int i, int flag)
{
	if (flag)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		else
			return (1);
	}
	return (0);
}

void	check_init(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

int	float_check(char *str)
{
	int	dot;
	int	spaceflag;
	int	i;

	i = space_check(str);
	if (str[i] == '-')
		i++;
	check_init(&dot, &spaceflag);
	while (str[i])
	{
		if (trailing_spaces(str, i, spaceflag))
			return (1);
		else
		{
			if (str[i] == '.')
				dot++;
			else if (!ft_isdigit(str[i]) && (str[i] == ' ' || str[i] == '\t'
					|| str[i] == '\n'))
				spaceflag = 1;
			else if (!ft_isdigit(str[i]))
				return (0);
		}
		i++;
	}
	return (dot <= 1);
}

int	sign_check(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}
