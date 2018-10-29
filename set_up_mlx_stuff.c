/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_mlx_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:12:07 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/02 13:14:27 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	set_up_mlx_stuff(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3d");
	info->display_img = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
	info->skybox_img = mlx_new_image(info->mlx, 360, 1);
//	info->dim->tex_w = TEX_WIDTH;
//	info->dim->tex_h = TEX_HEIGHT;
//	info->dim->win_w = WIN_WIDTH;
//	info->dim->win_h = WIN_HEIGHT;
}
