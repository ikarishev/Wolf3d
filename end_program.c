/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:37:14 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/01 13:54:28 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	end_program(t_info *info)
{
	free_info(info);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

int		exit_hook(void *in)
{
	t_info		*info;
	info = (t_info*)in;
	end_program(info);
	return (0);
}
