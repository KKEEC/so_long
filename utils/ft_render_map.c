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

    ft_print2dchararr(mlxdata->map);

    while (mlxdata->map[x])
    {
        printf("segfault here at outer loop x: %d  y: %d\n", x, y);
        y = 0;
        while (mlxdata->map[x][y])
        {
            printf("segfault here at inner loop x: %d  y: %d\n", x, y);
            px = y * 32;
            py = x * 32;
            if (mlxdata->map[x][y] == '1')
                mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->wall_img, px, py);
            else if (mlxdata->map[x][y] == '0')
                mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->floor_img, px, py);
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