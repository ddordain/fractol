/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:21:53 by ddordain          #+#    #+#             */
/*   Updated: 2022/02/22 10:17:09 by ddordain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>
# include <stdlib.h>

/* libft */
# include "../libft/include/libft.h"

/* mlx */
# include <mlx.h>

# define M "mandelbrot"
# define J "julia"

# define MSG_ERR_0 "error, please use ./fractol mandelbrot \
or ./fractol julia\n"

# define WIDTH 800
# define HEIGHT 800

# define ITER_MAX 100
# define ESC 65307
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

typedef struct s_data
{
	char	*name;
	int		j_r;
	int		j_i;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_l;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	float	zoom;
	float	ypos;
	float	xpos;
	float	cx;
	float	cy;
}				t_data;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

void	init(t_data *data);
int		mandelbrot(t_complex z, t_complex c);
int		julia(t_complex z, t_complex c);
void	draw(t_data *data);
int		zoom(int key, int x, int y, t_data *data);
int		arrow(int key, t_data *data);
double	ft_atof(const char *str);

#endif