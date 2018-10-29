/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:14:36 by ikarishe          #+#    #+#             */
/*   Updated: 2018/09/06 13:14:24 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	fill_skybox(t_info *info)
{
	int w;
	int h;

	w = 360;
	h = 300;
	info->skybox_img = mlx_xpm_file_to_image(info->mlx,
			"img/skyscape360.XPM", &w, &h);
}

int		grab_sky_color(int sky_x, int sky_y, t_info *info)
{
	int color;

	color = image_get_pxl(info->skybox_img, sky_x, sky_y, 360);
	return (color);
}

void	skybox_to_display(t_info *info, int start_angle, int end_angle)
{
	int disp_x;
	int disp_y;
	int	sky_x;
	int	sky_y;
	int color;

	double	arc_length;
	int		arc_num;

	arc_num = 1;

	disp_x = 0;
	disp_y = 0;
	sky_x = start_angle;
	sky_y = 0;
	
	if (start_angle < 0)
		sky_x = start_angle + 360;
	if (start_angle > end_angle)
		arc_length = ((double)WIN_WIDTH / (double)((361 - start_angle) + end_angle));
	else if (start_angle == 0)
		arc_length = ((double)WIN_WIDTH / (double)(end_angle + 1 - start_angle));
	else
		arc_length = ((double)WIN_WIDTH / (double)(end_angle - start_angle));

//	printf("(s%d %de) sx-%d, ac-%f\n", start_angle, end_angle, sky_x, arc_length);
	while (disp_y < WIN_HEIGHT / 2)
	{
		while (disp_x < WIN_WIDTH)
		{
//			if (disp_x > (double)(arc_length * (sky_x - start_angle + 1)))
			if (disp_x > (double)(arc_length * arc_num))
			{
				arc_num++;
				sky_x++;
				if (sky_x >= 360)
					sky_x = sky_x - 360;
			}
			color = grab_sky_color(sky_x, sky_y, info);
			image_set_pixel(info->display_img, disp_x, disp_y, color);
			disp_x++;
		}
		disp_x = 0;
		arc_num = 1;
		sky_x = start_angle;
		disp_y++;
		sky_y++;
	}

}

void	draw_floor(t_info *info)
{
	int i;
	int j;
	int color;


	i = 0;
	j = WIN_HEIGHT / 2;
	color = 0x004C0099;
	while (j < WIN_HEIGHT / 2 + 100)
	{
		while (i < WIN_WIDTH)
		{
			image_set_pixel(info->display_img, i, j, color);
			i++;
		}
		i = 0;
		j++;
	}
	i = 0;
	j = WIN_HEIGHT / 2 + 100 ;
	int	img_y;
	img_y = 0;
	if (info->char_map[(int)(info->player->x)][(int)(info->player->y)] == '#')
	{
		while (j < WIN_HEIGHT)
		{
			while (i < WIN_WIDTH)
			{	
				image_set_pixel(info->display_img, i, j, image_get_pxl(info->mountain_floor, i, img_y, 800));
				i++;
			}
			i = 0;
			j++;
			img_y++;
		}
	}
}

void	draw_sky_box(t_info *info)
{
	int start_angle;
	int end_angle;
	double	direction;

	direction = atan2(info->player->dir_y, info->player->dir_x) * 180.0 / M_PI;
	if (direction < 0)
		direction += 360;
	start_angle = direction - 45;
	end_angle = direction + 45;
	if (start_angle < 0)
		start_angle += 360;
	skybox_to_display(info, start_angle, end_angle);
//	draw_floor(info);
}
