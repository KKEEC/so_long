/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:16:20 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 13:37:23 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handlecharmove(t_mlx_data *mlxdata, int newposx, int newposy)
{
	int	oldpx;
	int	oldpy;
	int	newpx;
	int	newpy;

	oldpx = mlxdata->player_posx * mlxdata->img_width;
	oldpy = mlxdata->player_posy * mlxdata->img_height;
	mlxdata->totalmoves++;
	if (mlxdata->map[newposx][newposy] == 'C')
		mlxdata->collectibles--;
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win,
		mlxdata->floor_img, oldpy, oldpx);
	mlxdata->map[mlxdata->player_posx][mlxdata->player_posy] = '0';
	mlxdata->map[newposx][newposy] = 'P';
	mlxdata->player_posx = newposx;
	mlxdata->player_posy = newposy;
	newpx = newposx * mlxdata->img_width;
	newpy = newposy * mlxdata->img_height;
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win,
		mlxdata->player_img, newpy, newpx);
	ft_putstr("current moves: ");
	ft_putnbr(mlxdata->totalmoves);
	ft_putstr("\n");
}

static void	handleexit(t_mlx_data *mlxdata)
{
	mlxdata->totalmoves++;
	mlx_destroy_window(mlxdata->mlx, mlxdata->win);
	ft_free2darr(mlxdata->map);
	ft_putstr("Congratulations! ");
	ft_putstr("You collected all items and reached exit in ");
	ft_putnbr(mlxdata->totalmoves);
	ft_putstr(" moves. GAME OVER\n");
	exit(EXIT_SUCCESS);
}

static void	handleescape(t_mlx_data *mlxdata)
{
	mlx_destroy_window(mlxdata->mlx, mlxdata->win);
	ft_free2darr(mlxdata->map);
	exit (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_mlx_data *mlxdata)
{
	int	newposx;
	int	newposy;

	newposx = mlxdata->player_posx;
	newposy = mlxdata->player_posy;
	if (keycode == 65307)
		handleescape(mlxdata);
	else if (keycode == 65362 || keycode == 119)
		newposx = mlxdata->player_posx - 1;
	else if (keycode == 65364 || keycode == 115)
		newposx = mlxdata->player_posx + 1;
	else if (keycode == 65361 || keycode == 97)
		newposy = mlxdata->player_posy - 1;
	else if (keycode == 65363 || keycode == 100)
		newposy = mlxdata->player_posy + 1;
	if (mlxdata->map[newposx][newposy] == '0' ||
			mlxdata->map[newposx][newposy] == 'C')
		handlecharmove(mlxdata, newposx, newposy);
	else if (mlxdata->map[newposx][newposy] == 'E' &&
			mlxdata->collectibles == 0)
		handleexit(mlxdata);
	return (0);
}

int	close_window(t_mlx_data *mlxdata)
{
	mlx_destroy_window(mlxdata->mlx, mlxdata->win);
	ft_free2darr(mlxdata->map);
	exit(EXIT_SUCCESS);
}
