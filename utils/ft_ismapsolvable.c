#include "../so_long.h"


void    ft_playerpos(char **map, int *x, int *y)
{
    int     i;
    int     j;

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

void    flood_fill(char **map, int x, int y, int *exit_found, int *collectibles_left)
{
    //stop if outofbounds hit a wall or already visited 'V'
    if (map[x][y] == '1' || map[x][y] == 'V')
        return ;
    // if we reach exit, mark as found
    if (map[x][y] == 'E')
        *exit_found = 1;
    //if we reach collectibles, decrease collectibles left
    if (map[x][y] == 'C')
        (*collectibles_left)--;
    //mark current pos as visited
    map[x][y] = 'V';

    flood_fill(map, x + 1, y, exit_found, collectibles_left); //down
    flood_fill(map, x - 1, y, exit_found, collectibles_left); //up
    flood_fill(map, x, y - 1, exit_found, collectibles_left); //left
    flood_fill(map, x, y + 1, exit_found, collectibles_left); //right
}

int    ft_ismapsolvable(char **map, t_mlx_data *mlxdata)
{
    int x;
    int y;
    int exit_found = 0;
    int collectibles_left = 0;

    //count collectibles
    x = 0;
    y = 0;
    while (map[x] != NULL)
    {
        y = 0;
        while (map[x][y] != '\0')
        {
            if (map[x][y] == 'C')
                collectibles_left++;
            y++;
        }
        x++;
    }
    mlxdata->collectibles = collectibles_left;
    ft_playerpos(map, &x, &y);

    flood_fill(map, x, y, &exit_found, &collectibles_left);

    if (exit_found == 1 && collectibles_left == 0)
        return 1;
    else
        return 0;

}