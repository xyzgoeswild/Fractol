/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:40:57 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/08/05 20:17:28 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//  Includes (to get the job done)
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// some cool colors!
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define LIME_SHOCK 0xCCFF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define ELECTRIC_BLUE 0x0066FF

//  Windown Size x.y
# define WIDTH 600
# define HEIGHT 600

// keysyms
# define PLUS 61
# define MINUS 45
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 0xff1b

//  --- Initializing Structs ---
typedef struct s_map
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}			t_map;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*title;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	zoom_in_out;
	double	escape_value;
	double	x;
	double	y;
	double	julia_x;
	double	julia_y;
	int		max_iteration;
}			t_fractal;
//  --- Initializing Structs End ---

// Functions Declaration
char		*ft_strnstr(const char *big, const char *little, size_t len);

double		screen_map(double unscaled_num, double new_min, double new_max,
				double old_max);
double		ft_atof(char *str);

t_complex	sum_complx(t_complex z1, t_complex z2);
t_complex	sqr_complx(t_complex z);

int			ft_strncmp(char *str1, char *str2, int n);
int			close_window(int key, t_fractal *fractol);
int			handle_key(int key, t_fractal *fractol);
int			check_arg(char *av, char *name);
int			handle_close(t_fractal *fractol);
int			mouse_handler(int keycode, int x, int y, t_fractal *fractol);
int			sign_check(char *str, int *i);
int			space_check(char *str);
int			increase_iteration(int keycode, t_fractal *fractol);
int			ft_isdigit(int c);
int			trailing_spaces(char *str, int i, int flag);
int			check_julia(char *av1, char *av2);
int			float_check(char *str);
int			sign_check(char *str, int *i);

void		check_init(int *i, int *j);
void		julia(t_fractal *fractol);
void		calculate_julia(int x, int y, t_fractal *fractol);
void		fractol_init(t_fractal *fractol);
void		render_fractol(t_fractal *fractol);
void		handle_pxl(int x, int y, t_fractal *fractol);
void		put_pixel(int x, int y, t_img *img, int color);
void		display_error(int fd);
void		malloc_error(void);

#endif
