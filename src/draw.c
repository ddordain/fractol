/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:34:57 by ddordain          #+#    #+#             */
/*   Updated: 2022/02/14 12:52:59 by ddordain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	img_pxl_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = data->bpp - 8;
	pixel = data->addr + (y * data->size_l + x * (data->bpp / 8));
	while (i >= 0)
	{
		if (data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

static void	print_pixel_m(t_data *data, int (*f)(t_complex, t_complex))
{
	long double		x;
	long double		y;
	t_complex		c;
	t_complex		z;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.x = data->xpos + (x * data->zoom);
			c.y = data->ypos + (y * data->zoom);
			img_pxl_put(data, x, y, f(z, c));
			y++;
		}
		x++;
	}
}

static void	print_pixel_j(t_data *data, int (*f)(t_complex, t_complex))
{
	long double		x;
	long double		y;
	t_complex		c;
	t_complex		z;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.x = 0.285;
			c.y = 0.01;
			z.x = data->xpos + (x * data->zoom);
			z.y = data->ypos + (y * data->zoom);
			img_pxl_put(data, x, y, f(z, c));
			y++;
		}
		x++;
	}
}

void	draw(t_data *data)
{
	if (ft_strncmp(data->name, M, ft_strlen(M)) == 0)
		print_pixel_m(data, &mandelbrot);
	else
		print_pixel_j(data, &julia);
}
