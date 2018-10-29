/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:14:57 by ikarishe          #+#    #+#             */
/*   Updated: 2018/09/06 14:54:04 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void		init_player(t_info *info)
{
	info->player->x = 50;
	info->player->y = 50;
	info->player->z = 0;
	info->player->x_loc = 10;
	info->player->y_loc = 10;
	info->player->dir_x = 1;
	info->player->dir_y = 0;
	info->player->move_speed = 0.1;
	info->player->rot_speed = 0.1;
}

void		init_plane(t_info *info)
{
	info->plane->x = 0;
	info->plane->y = 0.66;
}

void		init_clock(t_info *info)
{
	info->clock->need_update = 0;
	info->clock->last_time = clock();
}

void		free_info(t_info *info)
{
	free(info->player);
	free(info->ray);
	free(info->plane);
	free(info->line);
	free(info->clock);
}

void		init_mouse(t_info *info)
{
	info->mouse->last_x = 0;
	info->mouse->last_y = 0;
	info->mouse->last_dif_x = -10000;
	info->mouse->min_x = 0;
	info->mouse->max_x = 0;
	info->mouse->x = 0;
	info->mouse->y = 0;
}

void		init_keyboard(t_info *info)
{
	info->keys->index = (char*)malloc(sizeof(char) * 100);
	info->keys->press = (char*)malloc(sizeof(char) * 100);
	ft_bzero(info->keys->index, 100);
	ft_strcat(info->keys->index, "asdfhgzxcv bqweryt123465=97-80]ou[ip lj'k;\\,/nm.  `");
	ft_bzero(info->keys->press, 100);
	ft_strcat(info->keys->press, "0000000000000000000000000000000000000000000000000000");
	printf("%s\n", info->keys->index);
}

void		init_info(t_info *info)
{
	printf("init player\n");
	info->player = (t_player*)malloc(sizeof(t_player));
	init_player(info);

	printf("init raystuff\n");
	info->ray = (t_ray*)malloc(sizeof(t_ray));
	info->plane = (t_plane*)malloc(sizeof(t_plane));
	init_plane(info);
	info->line = (t_line*)malloc(sizeof(t_line));

	printf("init clock\n");
	info->clock = (t_my_clock*)malloc(sizeof(t_my_clock));
	init_clock(info);

	printf("init keyboard\n");
	info->keys = (t_keys*)malloc(sizeof(t_keys*));
	init_keyboard(info);

	printf("init mouse\n");
	info->mouse = (t_mouse*)malloc(sizeof(t_mouse));
	init_mouse(info);

	printf("init level\n");
	info->level = ft_strdup( "level0/");

	printf("init maps\n");
	info->col_map = (t_map*)malloc(sizeof(t_map));
	info->tex_map = (t_map*)malloc(sizeof(t_map));
}
