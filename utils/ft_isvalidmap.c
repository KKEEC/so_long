#include "../so_long.h"

int is_valid_char(char c)
{
    if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
        return 1;
    return 0;
}

int is_rectangular(char **map)
{
    int rowlen;
    int i;

    rowlen = ft_strlen(map[0]);
    i = 1;
    while (map[i] != NULL)
    {
        if (ft_strlen(map[i]) != rowlen)
            return (0);
        i++;
    }
    return 1;
}

int is_closedwalls(char **map)
{
    int i = 0;
    int last_row = 0;
    int len = ft_strlen(map[0]);

    // Find the last row index
    while (map[last_row] != NULL)
        last_row++;
    last_row--;  // Last valid row

    // Check first and last row
    while (i < len)  
    {
        if (map[0][i] != '1' || map[last_row][i] != '1')
            return 0;
        i++;
    }

    // Check first and last column
    i = 0;
    while (map[i] != NULL)
    {
        if (map[i][0] != '1' || map[i][len - 1] != '1')
            return 0;
        i++;
    }
    
    return 1;
}


int  has_requiredchar(char **map)
{
    int     player;
    int     exit;
    int     collectible;
    int     i;
    int     j;

    player = 0;
    exit = 0;
    collectible = 0;
    i = 0;
    j = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'P')
                player++;
            else if (map[i][j] == 'E')
                exit++;
            else if (map[i][j] == 'C')
                collectible++;
            j++;
        }
        i++;
    }
    if (player == 1 && exit == 1 && collectible >= 1)
        return 1;
    else
        return 0;
}


int     isvalidmap(char **map)
{
    if (is_rectangular(map) == 0)
    {
        write(1, "map not rectangular\n", 21);
        return 0;
    }
    if (is_closedwalls(map) == 0)
    {
        write(1, "map not closed by walls\n", 25);
        return 0;
    }
    int i;
    int j;

    i = 0;
    j = 0;

    while (map[i] != NULL)
    {
        j = 0;
        while(map[i][j])
        {
            if (is_valid_char(map[i][j]) == 0)
            {
                write(1, "Invalid character in map\n", 26);
                return 0;
            }
            j++;
        }
        i++;
    }
    if (has_requiredchar(map) == 0)
    {
        write(1, "Invalid (collectible, player or exit)\n", 39);
        return 0;
    }

    return 1;
}