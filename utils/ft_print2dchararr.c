#include "../so_long.h"

void  ft_print2dchararr(char **strs)
{
    int     i;

    i = 0;
    if (!strs)
        return ;
    while (strs[i] != NULL)
    {
        write(1, strs[i], ft_strlen(strs[i]));
        write(1, "\n", 1);
        i++;
    }
}