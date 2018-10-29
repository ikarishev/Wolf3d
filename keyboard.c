/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:52:13 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/09 13:22:29 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

/*int     my_key_funct(int keycode, void *in)
{
	t_info *info;

	info = (t_info*)in;
	
	check_need_update(info);

	if (keycode == 53)
		end_program(info);
	if (keycode == 126 || keycode == 124 || keycode == 123 || keycode == 124
			|| keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		move_player(info, keycode);
	printf("%d - keycode\n", keycode);

	mlx_clear_window(info->mlx, info->win);
	mlx_destroy_image(info->mlx, info->display_img);
	info->display_img = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
	draw_sky_box(info);
	raycast(info);
	mlx_put_image_to_window(info->mlx, info->win, info->display_img, 0, 0);

	return (0);
}*/

int		key_press(int keycode, void *in)
{
	t_info *info;

	info = (t_info*)in;
	if (keycode == 53)
		end_program(info);
	if (keycode >= 100)
		return (0);
	else
		info->keys->press[keycode] = '1';
//	printf("keycode - %d, %c\n", keycode, info->keys->index[keycode]);
	(void)keycode;
	return (0);
}

int		key_release(int keycode, void *in)
{
	t_info *info;
	
	info = (t_info*)in;
	if (keycode >= 100)
		return (0);
	else
		info->keys->press[keycode] = '0';
	(void)keycode;
	return (0);
}
