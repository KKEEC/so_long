#include "../so_long.h"

void    ft_render_map(t_mlx_data *mlxdata)
{
    int x;
    int y;
    int px;
    int py;

    x = 0;
    y = 0;
    px = 0;
    py = 0;

    //ft_print2dchararr(mlxdata->map);

    // First, draw the floor everywhere
    while (mlxdata->map[x])
    {
        y = 0;
        while (mlxdata->map[x][y])
        {
            px = y * mlxdata->img_width;
            py = x * mlxdata->img_height;

            // Draw floor first
            mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->floor_img, px, py);

            y++;
        }
        x++;
    }

    // Now, draw walls, player, collectibles, and exits
    x = 0;
    while (mlxdata->map[x])
    {
        y = 0;
        while (mlxdata->map[x][y])
        {
            px = y * mlxdata->img_width;
            py = x * mlxdata->img_height;

            if (mlxdata->map[x][y] == '1')
                mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->wall_img, px, py);
            else if (mlxdata->map[x][y] == 'P')
                mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->player_img, px, py);
            else if (mlxdata->map[x][y] == 'C')
                mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->collectible_img, px, py);
            else if (mlxdata->map[x][y] == 'E')
                mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->exit_img, px, py);

            y++;
        }
        x++;
    }
}
