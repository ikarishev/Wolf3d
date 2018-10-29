/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:54:20 by ikarishe          #+#    #+#             */
/*   Updated: 2018/09/06 14:54:27 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	move_forward(t_info *info)
{
	(void)info;

//	if (info->col_map->map[(int)(info->player->x + info->player->dir_x *
//				info->player->move_speed)][(int)info->player->y] == 0)
		info->player->x += info->player->dir_x * info->player->move_speed;
//	if (info->col_map->map[(int)info->player->x][(int)(info->player->y +
//				info->player->dir_y * info->player->move_speed)] == 0)
		info->player->y += info->player->dir_y * info->player->move_speed;

	return ;
}

void	move_backward(t_info *info)
{
	(void)info;

//	if (info->col_map->map[(int)(info->player->x - info->player->dir_x *
//				info->player->move_speed)][(int)info->player->y] == 0)
		info->player->x -= info->player->dir_x * info->player->move_speed;
//	if (info->col_map->map[(int)info->player->x][(int)(info->player->y -
//				info->player->dir_y * info->player->move_speed)] == 0)
		info->player->y -= info->player->dir_y * info->player->move_speed;


	return ;
}

void	strafe_right(t_info *info)
{
	(void)info;


//	if (info->col_map->map[(int)(info->player->x - info->player->dir_y *
//				info->player->move_speed)][(int)info->player->y] == 0)
		info->player->x += (info->player->dir_y * info->player->move_speed);


//	if (info->col_map->map[(int)info->player->x][(int)(info->player->y -
//				info->player->dir_x * info->player->move_speed)] == 0)
		info->player->y += (-(info->player->dir_x * info->player->move_speed));



	return ;
}

void	strafe_left(t_info *info)
{
	(void)info;

//	if (info->col_map->map[(int)(info->player->x + info->player->dir_y *
//				info->player->move_speed)][(int)info->player->y] == 0)
		info->player->x += (-(info->player->dir_y * info->player->move_speed));


//	if (info->col_map->map[(int)info->player->x][(int)(info->player->y +
//				info->player->dir_x * info->player->move_speed)] == 0)
		info->player->y += (info->player->dir_x * info->player->move_speed);


	return ;
}

void	move_player(t_info *info)
{
	if (info->keys->press[13] == '1')
		move_forward(info);
	if (info->keys->press[1] == '1')
		move_backward(info);
	if (info->keys->press[0] == '1')
		strafe_right(info);
	if (info->keys->press[2] == '1')
		strafe_left(info);
	if (info->player->x <= 15 || info->player->x >= 85 ||
			info->player->y <= 15 || info->player->y >= 85)
	{
		init_player(info);
		init_plane(info);
	}
}
