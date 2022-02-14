/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:30:45 by ddordain          #+#    #+#             */
/*   Updated: 2022/02/14 12:53:14 by ddordain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractal");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->size_l, \
				&data->endian);
	data->zoom = 1;
	data->xpos = 0;
	data->ypos = 0;
}
