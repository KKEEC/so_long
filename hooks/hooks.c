#include "../so_long.h"

int key_hook(int keycode, t_mlx_data *mlxdata)
{
    int newposx = mlxdata->player_posx;
    int newposy = mlxdata->player_posy;

    if (keycode == 65307) // ESC key
    {
        mlx_destroy_window(mlxdata->mlx, mlxdata->win);
        ft_free2darr(mlxdata->map); // Close window
        exit(EXIT_SUCCESS); // Exit the program
    }
    else if (keycode == 65362 || keycode == 119) // W or up arrow
    {
        newposx = mlxdata->player_posx - 1;
    }
    else if (keycode == 65364 || keycode == 115) // S or down arrow
    {
        newposx = mlxdata->player_posx + 1;
    }
    else if (keycode == 65361 || keycode == 97) // A or left arrow
    {
        newposy = mlxdata->player_posy - 1;
    }
    else if (keycode == 65363 || keycode == 100) // D or rigfht arrow
    {
        newposy = mlxdata->player_posy + 1;
    }
    if (mlxdata->map[newposx][newposy] == '0' || mlxdata->map[newposx][newposy] == 'C')
    {
                // Draw the old player position as the background (floor)
        mlxdata->totalmoves++;
        if (mlxdata->map[newposx][newposy] == 'C')
            mlxdata->collectibles--;
        int oldPx = mlxdata->player_posx * mlxdata->img_width;
        int oldPy = mlxdata->player_posy * mlxdata->img_height;
        mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->floor_img, oldPy, oldPx);

        // Update the player position on the map
        mlxdata->map[mlxdata->player_posx][mlxdata->player_posy] = '0'; // Set the old position to floor
        mlxdata->map[newposx][newposy] = 'P'; // Set the new position to player

        mlxdata->player_posx = newposx;
        mlxdata->player_posy = newposy;

        // Draw the new player position
        int newPx = newposx * mlxdata->img_width;
        int newPy = newposy * mlxdata->img_height;
        mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->player_img, newPy, newPx); 
        ft_putstr("current moves: ");
        ft_putnbr(mlxdata->totalmoves);
        ft_putstr("\n");
    }
    else if (mlxdata->map[newposx][newposy] == 'E' && mlxdata->collectibles == 0)
    {
        mlxdata->totalmoves++;
        mlx_destroy_window(mlxdata->mlx, mlxdata->win);
        ft_free2darr(mlxdata->map);
        ft_putstr("Congratulations! ");
        ft_putstr("You collected all items and reached exit in ");
        ft_putnbr(mlxdata->totalmoves);
        ft_putstr(" moves. GAME OVER\n");
        exit(EXIT_SUCCESS); // Exit the program
    }



    return 0;
}

// Close event when the window's X button is clicked
int close_window(t_mlx_data *mlxdata)
{
    mlx_destroy_window(mlxdata->mlx, mlxdata->win); // Close window
    ft_free2darr(mlxdata->map);
    exit(EXIT_SUCCESS); // Exit the program
}
