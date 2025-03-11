#ifndef SO_LONG_H
# define SO_LONG_H


# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>


typedef struct s_mlx_data
{
    void    *mlx;
    void    *win;
    char    **map;

} t_mlx_data;

// Function prototypes
char    *read_map_file(const char *filename);
int     key_hook(int keycode, t_mlx_data *mlxwin);
int     close_window(t_mlx_data *mlxwin);
char	**ft_split(const char *str, char c);
void  ft_print2dchararr(char **strs);
void    ft_free2darr(char **arr);
int     ft_strlen(char *str);
int     isvalidmap(char **map);
int    ft_ismapsolvable(char **map);

#endif


