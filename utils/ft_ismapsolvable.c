/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismapsolvable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:51:59 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 12:17:48 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_playerpos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y, int *exitcol)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'E')
		exitcol[0] = 1;
	if (map[x][y] == 'C')
		exitcol[1]--;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y, exitcol);
	flood_fill(map, x - 1, y, exitcol);
	flood_fill(map, x, y - 1, exitcol);
	flood_fill(map, x, y + 1, exitcol);
}

int	ft_ismapsolvable(char **map, t_mlx_data *mlxdata)
{
	int			x;
	int			y;
	static int	exitcol[2] = {0};

	x = 0;
	y = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 'C')
				exitcol[1]++;
			y++;
		}
		x++;
	}
	mlxdata->collectibles = exitcol[1];
	ft_playerpos(map, &x, &y);
	flood_fill(map, x, y, exitcol);
	if (exitcol[0] == 1 && exitcol[1] == 0)
		return (1);
	else
		return (0);
}
