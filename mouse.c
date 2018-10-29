/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:29:23 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/03 14:56:57 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"
#define SCREEN_RES_X 2560;

/*int		hook_mousedown(int button, int x, int y, t_info *info)
  {
  t_pxl_point **map;

  map = info->map;
  if (button == 4)
  {
  info->zoom = info->zoom * 1.1;
  init_pixels(info);
  put_pixels(info->map, info);
  }
  else if (button == 5)
  {
  info->zoom = info->zoom / 1.1;
  init_pixels(info);
  put_pixels(info->map, info);
  }
  if (button == 1)
  {
  info->x_offset = (*map)[x + (y * WIDTH)].num.x;
  info->y_offset = (*map)[x + (y * WIDTH)].num.y;
  init_pixels(info);
  put_pixels(info->map, info);
  }
  info->mouse->is_down = button;
  return (0);
  }

  int		hook_mouseup(int button, int x, int y, t_info *info)
  {
  (void)x;
  (void)y;
  (void)button;
  info->mouse->is_down = 0;
  return (0);
  }*/

void	rotate_right(t_info *info)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = info->player->dir_x;
	old_plane_x = info->plane->x;
	info->player->dir_x = info->player->dir_x * cos(info->player->rot_speed)
		- info->player->dir_y * sin(info->player->rot_speed);
	info->player->dir_y = old_dir_x * sin(info->player->rot_speed) +
		info->player->dir_y * cos(info->player->rot_speed);
	info->plane->x = info->plane->x * cos(info->player->rot_speed) -
		info->plane->y * sin(info->player->rot_speed);
	info->plane->y = old_plane_x * sin(info->player->rot_speed) +
		info->plane->y * cos(info->player->rot_speed);
}

void	rotate_left(t_info *info)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = info->player->dir_x;
	old_plane_x = info->plane->x;
	info->player->dir_x = info->player->dir_x * cos(-(info->player->rot_speed))
		- info->player->dir_y * sin(-(info->player->rot_speed));
	info->player->dir_y = old_dir_x * sin(-(info->player->rot_speed)) +
		info->player->dir_y * cos(-(info->player->rot_speed));
	info->plane->x = info->plane->x * cos(-(info->player->rot_speed)) -
		info->plane->y * sin(-(info->player->rot_speed));
	info->plane->y = old_plane_x * sin(-(info->player->rot_speed)) +
		info->plane->y * cos(-(info->player->rot_speed));
}

int		hook_mousemove(int x, int y, t_info *info)
{
	if (info->mouse->last_x != info->mouse->x)
		info->mouse->last_dif_x = info->mouse->last_x;
	info->mouse->last_x = info->mouse->x;
	info->mouse->last_y = info->mouse->y;
	info->mouse->x = x;
	info->mouse->y = y;
	if (x < info->mouse->min_x)
		info->mouse->min_x = x;
	if (x > info->mouse->max_x)
		info->mouse->max_x = x;
//	printf("(%d, %d, ld_x(%d)) -> (%d, %d)  max_%d, min_%d\n", info->mouse->last_x, info->mouse->last_y, info->mouse->last_dif_x,
//			info->mouse->x, info->mouse->y, info->mouse->max_x, info->mouse->min_x);
	if (info->mouse->x < info->mouse->last_x)
	{
		rotate_left(info);
//		printf("left");
	}
	else if (info->mouse->x > info->mouse->last_x)
	{
		rotate_right(info);
//		printf("right");
	}
	else if (info->mouse->last_x == info->mouse->x)
	{
		if (x == info->mouse->max_x || x == info->mouse->min_x)
		{
			if (info->mouse->last_dif_x < info->mouse->x)
			{
				rotate_right(info);
//				printf("right");
			}
			else
			{
				rotate_left(info);
//				printf("left");
			}
		}
//		else
//			printf("@");
	}
//	printf("\n");
	return (0);
}

//CGWarpMouseCursorPosition - sets the mouse cursor to a certain place (middle of window)
//CGDisplayHideCursor - hides cursor
