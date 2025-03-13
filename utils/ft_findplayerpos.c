#include "../so_long.h"

void    ft_findplayerpos(t_mlx_data *mlxdata)
{
    int x;
    int y;
    
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