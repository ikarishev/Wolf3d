/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:03:23 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/10 13:36:18 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	load_textures(t_info *info)
{
	int w;
	int h;
	int w2;
	int	h2;

	h2 = 300;
	w2 = 800;

	w = 64;
	w = 64;
	info->sea_tex = mlx_xpm_file_to_image(info->mlx, 
			"tex/sea1_tex.XPM" , &w, &h);
	info->tree1_tex = mlx_xpm_file_to_image(info->mlx,
			"tex/grass2_tex.XPM", &w, &h);
	info->mount1_tex = mlx_xpm_file_to_image(info->mlx,
			"tex/mount1_tex.XPM", &w, &h);
	info->road1_tex = mlx_xpm_file_to_image(info->mlx,
			"tex/road1_tex.XPM", &w, &h);
	info->sand1_tex = mlx_xpm_file_to_image(info->mlx,
			"tex/sand1_tex.XPM", &w, &h);
	info->mountain_floor = mlx_xpm_file_to_image(info->mlx,
			"tex/mountainFloor.XPM", &w2, &h2);
}
