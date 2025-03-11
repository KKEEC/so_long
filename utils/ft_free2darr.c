#include "../so_long.h"

void    ft_free2darr(char **arr)
{
    int     i;
    
    i = 0;
    if (arr == NULL)
        return ;
    while (arr[i] != NULL)
    {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    free(arr);
    arr = NULL;
}