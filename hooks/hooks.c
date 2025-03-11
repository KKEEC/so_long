#include "../so_long.h"

int key_hook(int keycode, t_mlx_data *mlxdata)
{
    printf("Key pressed: %d\n", keycode);
    if (keycode == 65307) // ESC key
    {
        mlx_destroy_window(mlxdata->mlx, mlxdata->win);
        ft_free2darr(mlxdata->map); // Close window
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
