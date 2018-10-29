/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:48:25 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/02 12:54:14 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	check_need_update(t_info *info)
{
	clock_t current_time;

	current_time = clock();
	if (((double)info->clock->last_time + TICK_MS) < current_time)
	{
		info->clock->need_update = 1;
		info->clock->last_time = current_time;
	}
	if (info->clock->need_update == 1)
	{
//		update(info);
		info->clock->need_update = 0;
	}
}
