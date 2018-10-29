/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:26:23 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/10 12:37:28 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

int		shade_color(int color, int y)
{
	if (y < WIN_HEIGHT * .67)
		color = dull_color_a_little(color);
	if (y < WIN_HEIGHT * .66)
		color = dull_color_a_little(color);
	if (y < WIN_HEIGHT * .65)
		color = dull_color_a_little(color);
	if (y < WIN_HEIGHT * .64)
		color = dull_color_a_little(color);
	if (y < WIN_HEIGHT * .62)
		color = dull_color_a_little(color);
	if (y < WIN_HEIGHT * .60)
		color = dull_color(color);
	return (color);
}

/*void	put_floor(int x, double floor_x_wall, double floor_y_wall, t_info *info)
  {
  double	dist_wall;
  double	current_dist;
  int		y;
  int		color;

  dist_wall = info->ray->prep_wall_dist;
  if (info->line->draw_end < 0)
  info->line->draw_end = WIN_HEIGHT;
  y = info->line->draw_end + 1;
  while (y <= WIN_HEIGHT)
  {
  current_dist = WIN_HEIGHT / (2.0 * y - WIN_HEIGHT);
  info->wall->weight = current_dist / dist_wall;
  info->wall->curr_floor_x = info->wall->weight * floor_x_wall +
  (1.0 - info->wall->weight) * info->ray->pos_x;
  info->wall->curr_floor_y = info->wall->weight * floor_y_wall +
  (1.0 - info->wall->weight) * info->ray->pos_y;
  info->wall->floor_tex_x = (int)(info->wall->curr_floor_x *
  TEX_WIDTH * 4) % TEX_WIDTH;
  info->wall->floor_tex_y = (int)(info->wall->curr_floor_y *
  TEX_HEIGHT * 4) % TEX_HEIGHT;
  color = image_get_pxl(info->def_floor_tex, info->wall->floor_tex_x,
  info->wall->floor_tex_y, TEX_WIDTH);
  color = shade_color(color, y);
  image_set_pixel(info->display_img, x, y, color);
  image_set_pixel(info->display_img, x, WIN_HEIGHT - y, color);
  y++;
  }
  }*/

/*void	draw_floor(int x, t_info *info)
  {
  double floor_x_wall;
  double floor_y_wall;

  if (info->ray->side == 0 && info->ray->dir_x > 0)
  {
  floor_x_wall = info->ray->map_x;
  floor_y_wall = info->ray->map_y + info->line->wall_x;
  }
  else if (info->ray->side == 0 && info->ray->dir_x < 0)
  {
  floor_x_wall = info->ray->map_x + 1.0;
  floor_y_wall = info->ray->map_y + info->line->wall_x;
  }
  else if (info->ray->side == 1 && info->ray->dir_y > 0)
  {
  floor_x_wall = info->ray->map_x + info->line->wall_x;
  floor_y_wall = info->ray->map_y;
  }
  else
  {
  floor_x_wall = info->ray->map_x + info->line->wall_x;
  floor_y_wall = info->ray->map_y + 1.0;
  }
  put_floor(x, floor_x_wall, floor_y_wall, info);
  }*/

void	draw_line(int x, int draw_start, int draw_end, t_info *info)
{
	int d;
	int tex_y;
	int color;

	color = 0x00FF00FF;
	while (draw_start < draw_end)
	{
		d = draw_start * 256 - WIN_HEIGHT * 128 + info->line->line_height * 128;
		tex_y = ((d * TEX_HEIGHT) / info->line->line_height) / 256;
		if (info->ray->hit != 0)
			color = 0x00FFFF00;
		//		if (info->ray->hit == 1)
		//			color = 0x00FF0000;
		if (info->ray->hit == 1)
			color = image_get_pxl2(info->sea_tex, info->line->tex_x, tex_y, TEX_WIDTH);
		else if (info->ray->hit == 2)
			color = image_get_pxl2(info->road1_tex, info->line->tex_x, tex_y, TEX_WIDTH);
		else if (info->ray->hit == 3)
			color = image_get_pxl2(info->tree1_tex, info->line->tex_x, tex_y, TEX_WIDTH);
		else if (info->ray->hit == 4)
			color = image_get_pxl2(info->mount1_tex, info->line->tex_x, tex_y, TEX_WIDTH);
		else if (info->ray->hit == 5)
			color = image_get_pxl2(info->sand1_tex, info->line->tex_x, tex_y, TEX_WIDTH);
		//		if (info->ray->hit == 2)
		//			color = image_get_pxl(info->fake_wall,
		//					info->line->tex_x, tex_y, TEX_WIDTH);
		//		else if (info->ray->hit == 3)
		//			color = image_get_pxl(info->fake_wall2,
		//					info->line->tex_x, tex_y, TEX_WIDTH);
		//		else if (info->ray->hit == 4)
		//			color = image_get_pxl(info->go_back,
		//					info->line->tex_x, tex_y, TEX_WIDTH);
		//		else
		//			color = image_get_pxl(info->def_wall_tex,
		//					info->line->tex_x, tex_y, TEX_WIDTH);
		if (color != -1)
		{
//			if (info->ray->side == 1)
//				color = dull_color(color);
			//		color = fade_color(color, info);
			image_set_pixel(info->display_img, x,
					(draw_start + info->player->z), color);
		}
		draw_start++;
	}
}
