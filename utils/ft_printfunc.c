#include "../so_long.h"

void    ft_putstr(char *str)
{
    int i;
    
    i = 0;

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
static  void ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putnbr(int   nbr)
{
    char *digits = "0123456789";
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(digits[nbr % 10]);
}