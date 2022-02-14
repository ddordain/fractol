/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:58:50 by ddordain          #+#    #+#             */
/*   Updated: 2022/02/14 12:54:31 by ddordain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	arrow(int key, t_data *data)
{	
	if (key == ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	else if (key == LEFT)
		data->xpos -= 10 / data->zoom;
	else if (key == UP)
		data->ypos -= 10 / data->zoom;
	else if (key == RIGHT)
		data->xpos += 10 / data->zoom;
	else if (key == DOWN)
		data->ypos += 10 / data->zoom;
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (EXIT_SUCCESS);
}

int	zoom(int key, int x, int y, t_data *data)
{
	if (key == ZOOM_IN)
	{
		data->zoom /= 1.1;
		data->xpos += data->zoom * (x - (WIDTH / 2));
		data->ypos += data->zoom * (y - (HEIGHT / 2));
	}
	else if (key == ZOOM_OUT)
	{
		data->zoom *= 1.1;
		data->xpos += data->zoom * (x - (WIDTH / 2));
		data->ypos += data->zoom * (y - (HEIGHT / 2));
	}
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (EXIT_SUCCESS);
}
