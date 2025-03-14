/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:21:38 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 13:30:28 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_drawfloor(t_mlx_data *mlxdata, int px, int py)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlxdata->map[x])
	{
		y = 0;
		while (mlxdata->map[x][y])
		{
			px = y * mlxdata->img_width;
			py = x * mlxdata->img_height;
			mlx_put_image_to_window(mlxdata->mlx, mlxdata->win,
				mlxdata->floor_img, px, py);
			y++;
		}
		x++;
	}
}

static void	ft_drawrest(t_mlx_data *mlxdata, int px, int py)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlxdata->map[x])
	{
		y = 0;
		while (mlxdata->map[x][y])
		{
			px = y * mlxdata->img_width;
			py = x * mlxdata->img_height;
			if (mlxdata->map[x][y] == 'C')
				mlx_put_image_to_window(mlxdata->mlx,
					mlxdata->win, mlxdata->collectible_img, px, py);
			else if (mlxdata->map[x][y] == 'E')
				mlx_put_image_to_window(mlxdata->mlx,
					mlxdata->win, mlxdata->exit_img, px, py);
			y++;
		}
		x++;
	}
}

static void	ft_drawwallplayer(t_mlx_data *mlxdata, int px, int py)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlxdata->map[x])
	{
		y = 0;
		while (mlxdata->map[x][y])
		{
			px = y * mlxdata->img_width;
			py = x * mlxdata->img_height;
			if (mlxdata->map[x][y] == '1')
				mlx_put_image_to_window(mlxdata->mlx,
					mlxdata->win, mlxdata->wall_img, px, py);
			else if (mlxdata->map[x][y] == 'P')
				mlx_put_image_to_window(mlxdata->mlx,
					mlxdata->win, mlxdata->player_img, px, py);
			y++;
		}
		x++;
	}
}

void	ft_render_map(t_mlx_data *mlxdata)
{
	int	px;
	int	py;

	px = 0;
	py = 0;
	ft_drawfloor(mlxdata, px, py);
	ft_drawwallplayer(mlxdata, px, py);
	ft_drawrest(mlxdata, px, py);
}
