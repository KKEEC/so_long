/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:02:31 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 14:43:27 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	init_andguardmap(t_mlx_data *mlxdata, char *mapfile)
{
	if (!mapfile)
		return ;
	mlxdata->map = ft_split(mapfile, '\n');
	if (!mlxdata->map)
	{
		ft_putstr("Error: Failed to split map.\n");
		exit(EXIT_FAILURE);
	}
}

static	void	checkmapvalidation(t_mlx_data *mlxdata, char *mapfile)
{
	char	**tempmap;

	tempmap = ft_split(mapfile, '\n');
	if (!tempmap)
	{
		ft_putstr("Error: Failed to split map for validation.\n");
		ft_free2darr(mlxdata->map);
		exit (EXIT_FAILURE);
	}
	if (isvalidmap(tempmap) == 0 || ft_ismapsolvable(tempmap, mlxdata) == 0)
	{
		ft_putstr("Error: Map is either invalid or not solvable \n");
		ft_free2darr(tempmap);
		ft_free2darr(mlxdata->map);
		exit(EXIT_FAILURE);
	}
	ft_free2darr(tempmap);
}

static void	handlemlxinitfail(t_mlx_data *mlxdata)
{
	if (!mlxdata->mlx)
	{
		ft_putstr("MLX initialisation failed.\n");
		ft_free2darr(mlxdata->map);
		exit(EXIT_FAILURE);
	}
	if (!mlxdata->win)
	{
		ft_putstr("MLX window creation failed. \n");
		ft_free2darr(mlxdata->map);
		exit(EXIT_FAILURE);
	}
}

static void	checkusagefail(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ./so_long <map_file.ber>\n");
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlxdata;
	char		*mapfile;

	mlxdata.totalmoves = 0;
	checkusagefail(argc);
	mapfile = read_map_file(argv[1]);
	if (!mapfile)
		return (EXIT_FAILURE);
	init_andguardmap(&mlxdata, mapfile);
	checkmapvalidation(&mlxdata, mapfile);
	mlxdata.mlx = mlx_init();
	handlemlxinitfail(&mlxdata);
	ft_loadtextures(&mlxdata);
	ft_findplayerpos(&mlxdata);
	mlxdata.win = mlx_new_window(mlxdata.mlx, ft_countwindowwidth(mlxdata),
			ft_countwindowheight(mlxdata), "so_long");
	handlemlxinitfail(&mlxdata);
	ft_render_map(&mlxdata);
	mlx_key_hook(mlxdata.win, key_hook, &mlxdata);
	mlx_hook(mlxdata.win, 17, 0, close_window, &mlxdata);
	mlx_loop(mlxdata.mlx);
	return (0);
}
