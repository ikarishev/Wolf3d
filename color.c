/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:55:22 by ikarishe          #+#    #+#             */
/*   Updated: 2018/02/06 18:40:58 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

int		dull_color(int color)
{
	int ret;
	int new_red;
	int new_green;
	int new_blue;

	new_red = (((color & 0x00F00000) / 2) & 0x00F00000) +
		(((color & 0x000F0000) / 2) & 0x000F0000);
	new_green = (((color & 0x0000F000) / 2) & 0x0000F000) +
		(((color & 0x00000F00) / 2) & 0x00000F00);
	new_blue = (((color & 0x000000F0) / 2) & 0x000000F0) +
		(((color & 0x0000000F) / 2) & 0x0000000F);
	ret = new_red + new_green + new_blue;
	return (ret);
}

int		dull_color_a_little(int color)
{
	int ret;
	int new_red;
	int new_green;
	int new_blue;

	ret = color;
	new_red = ((int)((ret & 0x00F00000) / 1.5) & 0x00F00000) +
		((int)((ret & 0x000F0000) / 1.5) & 0x000F0000);
	new_green = ((int)((ret & 0x0000F000) / 1.5) & 0x0000F000) +
		((int)((ret & 0x00000F00) / 1.5) & 0x00000F00);
	new_blue = ((int)((ret & 0x000000F0) / 1.5) & 0x000000F0) +
		((int)((ret & 0x0000000F) / 1.5) & 0x0000000F);
	ret = new_red + new_green + new_blue;
	return (ret);
}

int		fade_color(int color, t_info *info)
{
	double	distance;
	int		ret;
	int		new_red;
	int		new_blue;
	int		new_green;

	ret = color;
	distance = info->ray->prep_wall_dist;
	while (distance > 3)
	{
		new_red = ((int)((ret & 0x00F00000) / 1.1) & 0x00F00000) +
			((int)((ret & 0x000F0000) / 1.1) & 0x000F0000);
		new_green = ((int)((ret & 0x0000F000) / 1.1) & 0x0000F000) +
			((int)((ret & 0x00000F00) / 1.1) & 0x00000F00);
		new_blue = ((int)((ret & 0x000000F0) / 1.1) & 0x000000F0) +
			((int)((ret & 0x0000000F) / 1.1) & 0x0000000F);
		ret = new_red + new_green + new_blue;
		distance -= 0.2;
	}
	return (ret);
}
