#include "./mlx/mlx.h"
#include "so_long.h"


int main(int argc, char **argv)
{
    t_mlx_data mlxdata;
    char *mapfile;
    char **tempmap;

    if (argc != 2)
    {
        printf("Usage: %s <map_file.ber>\n", argv[0]);
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
        printf("Error: Failed to split map.\n");
        return EXIT_FAILURE;
    }
    //create temporary map for validation check and solve check
    tempmap = ft_split(mapfile, '\n'); // need to check split fail
    if (!tempmap)
    {
        printf("Error: Failed to split map for validation.\n");
        ft_free2darr(mlxdata.map);  // Free original map
        return EXIT_FAILURE;
    }
    if (isvalidmap(tempmap) == 0 || ft_ismapsolvable(tempmap) == 0)
    {
        printf("Error: Map is either invalid or not solvable.\n");
        ft_free2darr(tempmap);  // Free temporary map copy
        ft_free2darr(mlxdata.map);  // Free original map
        return EXIT_FAILURE;
    }
    printf("Map is valid and solvable.\n");
    ft_free2darr(tempmap);
    ft_print2dchararr(mlxdata.map);


    mlxdata.mlx = mlx_init();
    if (!mlxdata.mlx)
    {
        perror("mlx init failed");
        ft_free2darr(tempmap);
        return EXIT_FAILURE;
    }

    mlxdata.win = mlx_new_window(mlxdata.mlx, 800, 600, "so_long");
    if (!mlxdata.win)
    {
        perror("mlx window creation failed");
        ft_free2darr(tempmap);
        return EXIT_FAILURE;
    }
    //textures loaded
    ft_loadtextures(&mlxdata);

    //now render map;
    ft_render_map(&mlxdata);
    
    mlx_key_hook(mlxdata.win, key_hook, &mlxdata);
    mlx_hook(mlxdata.win, 17, 0, close_window, &mlxdata);

    mlx_loop(mlxdata.mlx);
    return 0;
}
