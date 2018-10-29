/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 13:56:26 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/09 14:12:10 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	image_set_pixel(t_image *image, int x, int y, int color)
{
/*
** Fix this wtf! t_image *image isn't a thing, you're feeding info->img,
**	which is a void pointer from mlx_new_img...
**
**	*image->img = info->img
**	*image->ptr = mlx_get_addrr (of that image)
**	// bbp, and endianness stuff in there as well... be proper
*/
	if (x < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	*(int *)(image->ptr + ((x + y * WIN_WIDTH) * 4)) = color;
}

int		image_get_pxl(t_image *image, int x, int y, int tex_width)
{
	return (*(int *)(image->ptr + ((x + y * tex_width) * 4)));
}

int		image_get_pxl2(t_image *image, int x, int y, int tex_width)
{
	if ((*(int *)(image->ptr + ((x + y * tex_width) * 4))) == 0x00FFFFFF)
		return (-1);
	return (*(int *)(image->ptr + ((x + y * tex_width) * 4)));
}
