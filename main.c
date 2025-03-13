#include "./mlx/mlx.h"
#include "so_long.h"


int main(int argc, char **argv)
{
    t_mlx_data mlxdata;
    char *mapfile;
    char **tempmap;
    mlxdata.totalmoves = 0;

    if (argc != 2)
    {
        ft_putstr("Usage: ./so_long <map_file.ber>\n");
        return EXIT_FAILURE;
    }

    mapfile = read_map_file(argv[1]);
    if (!mapfile)
        return (EXIT_FAILURE);
   // printf("%s\n", mapfile);
    //split map into 2d array
    mlxdata.map = ft_split(mapfile, '\n');// need to check split fail
    if (!mlxdata.map)
    {
        ft_putstr("Error: Failed to split map.\n");
        return EXIT_FAILURE;
    }
    //create temporary map for validation check and solve check
    tempmap = ft_split(mapfile, '\n'); // need to check split fail
    if (!tempmap)
    {
        ft_putstr("Error: Failed to split map for validation.\n");
        ft_free2darr(mlxdata.map);  // Free original map
        return EXIT_FAILURE;
    }
    if (isvalidmap(tempmap) == 0 || ft_ismapsolvable(tempmap, &mlxdata) == 0)
    {
        ft_putstr("Error: Map is either invalid or not solvable.\n");
        ft_free2darr(tempmap);  // Free temporary map copy
        ft_free2darr(mlxdata.map);  // Free original map
        return EXIT_FAILURE;
    }
    ft_putstr("Map is valid and solvable.\n");
    ft_free2darr(tempmap);
    //ft_print2dchararr(mlxdata.map);

    mlxdata.mlx = mlx_init();
    if (!mlxdata.mlx)
    {
        ft_putstr("mlx init failed\n");
        ft_free2darr(tempmap);
        return EXIT_FAILURE;
    }

    ft_loadtextures(&mlxdata);
    //textures loaded
    //after assets are ready and everything is okay find player position
    ft_findplayerpos(&mlxdata);
    //printf("image width: %d, image height: %d\n", mlxdata.img_width, mlxdata.img_height);

    mlxdata.win = mlx_new_window(mlxdata.mlx, ft_countwindowwidth(mlxdata), ft_countwindowheight(mlxdata), "so_long");
    if (!mlxdata.win)
    {
        ft_putstr("mlx window creation failed\n");
        ft_free2darr(tempmap);
        return EXIT_FAILURE;
    }
    

    //now render map;
    ft_render_map(&mlxdata);
    
    mlx_key_hook(mlxdata.win, key_hook, &mlxdata);
    mlx_hook(mlxdata.win, 17, 0, close_window, &mlxdata);

    mlx_loop(mlxdata.mlx);
    return 0;
}
