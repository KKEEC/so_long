/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findplayerpos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:49:45 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 11:51:29 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_findplayerpos(t_mlx_data *mlxdata)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlxdata->map[x] != NULL)
	{
		y = 0;
		while (mlxdata->map[x][y])
		{
			if (mlxdata->map[x][y] == 'P')
			{
				mlxdata->player_posx = x;
				mlxdata->player_posy = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
