/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:25:02 by ddordain          #+#    #+#             */
/*   Updated: 2022/02/22 14:56:33 by ddordain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_number(char *av)
{
	char	sign;
	char	dot;

	if (av == NULL)
		return (EXIT_FAILURE);
	sign = 0;
	dot = 0;
	while (*av)
	{
		if (*av == '+' || *av == '-')
			sign++;
		else if (*av == '.')
		{
			if (!ft_isdigit(*(av + 1)))
				return (EXIT_FAILURE);
			dot++;
		}
		else if (!ft_isdigit(*av))
			return (EXIT_FAILURE);
		if (sign > 1 || dot > 1)
			return (EXIT_FAILURE);
		av++;
	}
	return (EXIT_SUCCESS);
}

static int	security_check(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd(MSG_ERR_0, 2);
		return (EXIT_FAILURE);
	}
	else if (ft_strncmp(av[1], M, ft_strlen(M)) == 0 && ac == 2
		&& ft_strlen(av[1]) == ft_strlen(M))
		return (EXIT_SUCCESS);
	else if (ft_strncmp(av[1], J, ft_strlen(J)) == 0 && ac == 4
		&& ft_strlen(av[1]) == ft_strlen(J)
		&& check_number(av[2]) == 0 && check_number(av[3]) == 0)
		return (EXIT_SUCCESS);
	else
	{
		ft_putstr_fd(MSG_ERR_0, 2);
		return (EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (security_check(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else
	{
		data.name = av[1];
		if (ac == 4)
		{
			data.j_r = ft_atof(av[2]);
			data.j_i = ft_atof(av[3]);
		}
		init(&data);
		mlx_hook(data.mlx_win, 4, 1L << 2, zoom, &data);
		mlx_hook(data.mlx_win, 2, 1L << 0, arrow, &data);
		draw(&data);
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
		mlx_loop(data.mlx);
	}
	return (EXIT_SUCCESS);
}
