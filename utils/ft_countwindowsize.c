/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwindowsize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:47:04 by kkc               #+#    #+#             */
/*   Updated: 2025/03/14 10:49:58 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_countwindowheight(t_mlx_data mlxdata)
{
	int	heightofmap;
	int	winheight;

	winheight = 0;
	heightofmap = 0;
	while (mlxdata.map[heightofmap] != NULL)
		heightofmap++;
	winheight = heightofmap * mlxdata.img_height;
	return (winheight);
}

int	ft_countwindowwidth(t_mlx_data mlxdata)
{
	int	widthtofmap;
	int	winwidth;

	winwidth = 0;
	widthtofmap = 0;
	while (mlxdata.map[0][widthtofmap])
		widthtofmap++;
	winwidth = widthtofmap * mlxdata.img_width;
	return (winwidth);
}
