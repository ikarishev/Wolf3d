/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:18:14 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/09 14:15:41 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	check_next_square(t_info *info)
{
	if (info->ray->side_dist_x < info->ray->side_dist_y)
	{
		info->ray->side_dist_x += info->ray->delta_dist_x;
		info->ray->map_x += info->ray->step_x;
		info->ray->side = 0;
	}
	else
	{
		info->ray->side_dist_y += info->ray->delta_dist_y;
		info->ray->map_y += info->ray->step_y;
		info->ray->side = 1;
	}
	if ((info->col_map->map[info->ray->map_x][info->ray->map_y]) > 0)
		info->ray->hit = info->col_map->map[info->ray->map_x][info->ray->map_y];
}

void	set_line(t_info *info)
{
	int line_height;

	line_height = (int)(WIN_HEIGHT / info->ray->prep_wall_dist);
	info->line->line_height = line_height;
	info->line->draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (info->line->draw_start < 0)
		info->line->draw_start = 0;
	info->line->draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (info->line->draw_end >= WIN_HEIGHT)
		info->line->draw_end = WIN_HEIGHT - 1;
	if (info->ray->side == 0)
		info->line->wall_x = info->player->y_loc + info->ray->prep_wall_dist *
			info->ray->dir_y;
	else
		info->line->wall_x = info->player->x_loc + info->ray->prep_wall_dist *
			info->ray->dir_x;
	info->line->wall_x -= floor((info->line->wall_x));
	info->line->tex_x = (int)(info->line->wall_x * (double)TEX_WIDTH);
	if (info->ray->side == 0 && info->ray->dir_x > 0)
		info->line->tex_x = TEX_WIDTH - info->line->tex_x - 1;
	if (info->ray->side == 1 && info->ray->dir_y < 0)
		info->line->tex_x = TEX_WIDTH - info->line->tex_x - 1;
	info->line->def_color = 0x00FF00FF;
	if (info->ray->side == 1)
		info->line->def_color = dull_color(info->line->def_color);
}

void	set_wall_dist(t_info *info)
{
	if (info->ray->side == 0)
		info->ray->prep_wall_dist = (info->ray->map_x - info->ray->pos_x +
				(1 - info->ray->step_x) / 2) / info->ray->dir_x;
	else
		info->ray->prep_wall_dist = (info->ray->map_y - info->ray->pos_y +
				(1 - info->ray->step_y) / 2) / info->ray->dir_y;
}

void	set_step(t_info *info)
{
	if (info->ray->dir_x < 0)
	{
		info->ray->step_x = -1;
		info->ray->side_dist_x = (info->ray->pos_x - info->ray->map_x) *
			info->ray->delta_dist_x;
	}
	else
	{
		info->ray->step_x = 1;
		info->ray->side_dist_x = (info->ray->map_x + 1.0 - info->ray->pos_x)
			* info->ray->delta_dist_x;
	}
	if (info->ray->dir_y < 0)
	{
		info->ray->step_y = -1;
		info->ray->side_dist_y = (info->ray->pos_y - info->ray->map_y) *
			info->ray->delta_dist_y;
	}
	else
	{
		info->ray->step_y = 1;
		info->ray->side_dist_y = (info->ray->map_y + 1.0 - info->ray->pos_y)
			* info->ray->delta_dist_y;
	}
}

void	set_ray(t_info *info, int x, double *cam_x)
{
	*cam_x = 2 * x / (double)WIN_WIDTH - 1;
	info->ray->pos_x = info->player->x_loc;
	info->ray->pos_y = info->player->y_loc;
	info->ray->dir_x = info->player->dir_x + info->plane->x * *cam_x;
	info->ray->dir_y = info->player->dir_y + info->plane->y * *cam_x;
	info->ray->map_x = (int)info->player->x_loc;
	info->ray->map_y = (int)info->player->y_loc;
	info->ray->delta_dist_x = sqrt(1 + (info->ray->dir_y * info->ray->dir_y) /
			(info->ray->dir_x * info->ray->dir_x));
	info->ray->delta_dist_y = sqrt(1 + (info->ray->dir_x * info->ray->dir_x) /
			(info->ray->dir_y * info->ray->dir_y));
}

void	raycast(t_info *info)
{
	int		x;
	double	camera_x;
//	double	z_buffer[WIN_WIDTH];

	x = 0;
	while (x < WIN_WIDTH)
	{
		info->ray->hit = 0;
		set_ray(info, x, &camera_x);
		set_step(info);
		while (info->ray->hit == 0)
			check_next_square(info);
		set_wall_dist(info);
		set_line(info);
		draw_line(x, info->line->draw_start, info->line->draw_end, info);
//		z_buffer[x] = info->ray->prep_wall_dist;
//		draw_floor(x, info);
		x++;
	}
//	draw_sprites(info, z_buffer);
//	if (info->key_down->key == 49)
//		hand_to_display(info);
}
