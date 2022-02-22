/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:07:40 by ddordain          #+#    #+#             */
/*   Updated: 2022/02/22 15:10:50 by ddordain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter + rand());
	g = sin(0.3 * (double)iter + 2) * 127 + 128;
	b = sin(0.3 * (double)iter) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) \
			+ ((int)(255.999 * b));
	return (color);
}

int	mandelbrot(t_complex z, t_complex c)
{
	double	x_new;
	int		iter;

	iter = 0;
	if (iter == 0)
	{
		c.x = (2 * c.x) / WIDTH - 1.5;
		c.y = (2 * c.y) / HEIGHT - 1;
	}
	while ((pow(z.x, 2.0) + pow(z.y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(z.x, 2.0) - pow(z.y, 2.0) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = x_new;
		iter++;
	}
	return (rgb(iter));
}

int	julia(t_complex z, t_complex c)
{
	double	x_new;
	int		iter;

	iter = 0;
	if (iter == 0)
	{
		z.x = (2 * z.x) / WIDTH - 1;
		z.y = (2 * z.y) / HEIGHT - 1;
	}
	while ((pow(z.x, 2.0) + pow(z.y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(z.x, 2.0) - pow(z.y, 2.0) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = x_new;
		iter++;
	}
	return (rgb(iter));
}
