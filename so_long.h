/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:38:14 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 14:42:37 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*exit_img;
	void	*collectible_img;
	int		player_posx;
	int		player_posy;
	int		collectibles;
	int		totalmoves;
	int		img_width;
	int		img_height;
}	t_mlx_data;

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
// Function prototypes
char	*read_map_file(const char *filename);
int		key_hook(int keycode, t_mlx_data *mlxwin);
int		close_window(t_mlx_data *mlxwin);
char	**ft_split(const char *str, char c);
void	ft_print2dchararr(char **strs);
void	ft_free2darr(char **arr);
int		ft_strlen(char *str);
int		is_valid_char(char c);
int		isvalidmap(char **map);
int		ft_ismapsolvable(char **map, t_mlx_data *mlxdata);
void	ft_loadtextures(t_mlx_data *mlxdata);
void	ft_render_map(t_mlx_data *mlxdata);
int		ft_countwindowheight(t_mlx_data mlxdata);
int		ft_countwindowwidth(t_mlx_data mlxdata);
void	ft_findplayerpos(t_mlx_data *mlxdata);

#endif
