/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:52:06 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 11:26:29 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(char **map)
{
	int	rowlen;
	int	i;

	rowlen = ft_strlen(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != rowlen)
			return (0);
		i++;
	}
	return (1);
}

int	is_closedwalls(char **map)
{
	int	i;
	int	last_row;
	int	len;

	i = 0;
	last_row = 0;
	len = ft_strlen(map[0]);
	while (map[last_row] != NULL)
		last_row++;
	last_row--;
	while (i < len)
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	checkmap(char **map, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}

int	has_requiredchar(char **map)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	checkmap(map, &p, &e, &c);
	if (p == 1 && e == 1 && c >= 1)
		return (1);
	return (0);
}

int	isvalidmap(char **map)
{
	int	i;
	int	j;

	if (!is_rectangular(map) || !is_closedwalls(map) || !has_requiredchar(map))
	{
		ft_putstr("Map is not valid\n");
		return (0);
	}
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valid_char(map[i][j]) == 0)
			{
				ft_putstr("Invalid character in map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
