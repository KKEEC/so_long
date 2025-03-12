#include "../so_long.h"

void    ft_loadtextures(t_mlx_data *mlxdata)
{
    mlxdata->wall_img = mlx_xpm_file_to_image(mlxdata->mlx, "./assets/wall.xpm", &mlxdata->img_width, &mlxdata->img_height);
    mlxdata->floor_img = mlx_xpm_file_to_image(mlxdata->mlx, "./assets/floor.xpm", &mlxdata->img_width, &mlxdata->img_height);
    mlxdata->player_img = mlx_xpm_file_to_image(mlxdata->mlx, "./assets/char.xpm", &mlxdata->img_width, &mlxdata->img_height);
    mlxdata->collectible_img = mlx_xpm_file_to_image(mlxdata->mlx, "./assets/coin.xpm", &mlxdata->img_width, &mlxdata->img_height);
    mlxdata->exit_img = mlx_xpm_file_to_image(mlxdata->mlx, "./assets/exit.xpm", &mlxdata->img_width, &mlxdata->img_height);

    if (!mlxdata->wall_img || !mlxdata->floor_img || !mlxdata->player_img || !mlxdata->collectible_img || !mlxdata->exit_img)
    {
        write(1, "Error Loading textures\n", 24);
        exit(EXIT_FAILURE);
    }
    printf("textures loaded and saved\n");
   
}