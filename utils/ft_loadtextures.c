/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadtextures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:31:03 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 11:39:51 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_loadtextures(t_mlx_data *mlxdata)
{
	mlxdata->wall_img = mlx_xpm_file_to_image(mlxdata->mlx,
			"./assets/wall.xpm", &mlxdata->img_width,
			&mlxdata->img_height);
	mlxdata->floor_img = mlx_xpm_file_to_image(mlxdata->mlx,
			"./assets/floor.xpm", &mlxdata->img_width,
			&mlxdata->img_height);
	mlxdata->player_img = mlx_xpm_file_to_image(mlxdata->mlx,
			"./assets/char.xpm", &mlxdata->img_width,
			&mlxdata->img_height);
	mlxdata->collectible_img = mlx_xpm_file_to_image(mlxdata->mlx,
			"./assets/coin.xpm", &mlxdata->img_width,
			&mlxdata->img_height);
	mlxdata->exit_img = mlx_xpm_file_to_image(mlxdata->mlx,
			"./assets/exit.xpm", &mlxdata->img_width,
			&mlxdata->img_height);
	if (!mlxdata->wall_img || !mlxdata->floor_img
		|| !mlxdata->player_img
		|| !mlxdata->collectible_img || !mlxdata->exit_img)
	{
		ft_putstr("Error Loading textures\n");
		exit(EXIT_FAILURE);
	}
}
