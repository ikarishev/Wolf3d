/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:51:44 by ikarishe          #+#    #+#             */
/*   Updated: 2018/10/29 14:15:55 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"
#include <stdio.h>

void		key_commands(t_info *info)
{
//	printf("player direction (%f, %f)\n", info->player->dir_x, info->player->dir_y);
	move_player(info);
}

int		my_loop_hook(void *in)
{
	t_info		*info;
	clock_t		current_time;
	clock_t		end_time;

	info = in;
	current_time = clock();
	if (((double)info->clock->last_time + 10000) < current_time)
	{
		info->clock->need_update = 1;
		info->clock->last_time = current_time;
	}
	if (info->clock->need_update == 1)
	{
//		update(info);
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_image(info->mlx, info->display_img);
		info->display_img = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
		key_commands(info);
		draw_sky_box(info);
		char_map_to_local(info);
		raycast(info);
		int i;
		i = 1;
		while (i < 7)
		{
			char_map_to_local2(info, i);
			raycast(info);
			i++;
		}
		mlx_put_image_to_window(info->mlx, info->win, info->display_img, 0, 0);
		info->clock->need_update = 0;
		end_time = clock();
//		printf("%lu\n",  end_time - current_time);
	}
	return (0);
}

int		main(void)
{
	t_info		info;

	printf("init mlx\n");
	set_up_mlx_stuff(&info);
	printf("init info\n");
	init_info(&info);
	printf("init skybox\n");
	fill_skybox(&info);
	printf("loading textures\n");
	load_textures(&info);
//	printf("read map1.map\n");
//	read_map("maps/level0/map1.map", &info, info.col_map);
//	printf("xpm_to_char\n");
//	make_char_map(&info);
	printf("read char_map\n");
	read_char_map(&info);
	char_map_to_local(&info);
	raycast(&info);
	printf("display img\n");
	mlx_put_image_to_window(info.mlx, info.win, info.display_img, 0, 0);
	mlx_hook(info.win, 2, 1, &key_press, &info);
	mlx_hook(info.win, 3, 2, &key_release, &info);
	mlx_hook(info.win, 6, 1, hook_mousemove, &info);
//	mlx_hook(info.win, 4, 2, hook_mousedown, &info);
	mlx_hook(info.win, 17, 0, &exit_hook, &info);
	mlx_loop_hook(info.mlx, my_loop_hook, &info);
	mlx_loop(info.mlx);
	return (0);
}
