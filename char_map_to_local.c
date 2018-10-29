/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_map_to_local.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:55:12 by ikarishe          #+#    #+#             */
/*   Updated: 2018/09/06 14:42:42 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void	char_map_to_local(t_info *info)
{
	int start_x = info->player->x - 10;
	int start_y = info->player->y - 10;
	int	end_x = info->player->x + 10;
	int end_y = info->player->y + 10;
	info->col_map->height = 20;
	info->col_map->width = 20;

	int i = 0;
	int j = 0;
	while (i < 20)
	{
		while (j < 20)
		{
			info->col_map->map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}

	i = 0;
	j = 0;
	while (j < 20)
	{
		if (info->char_map[start_x][start_y] == 'C')
			info->col_map->map[i][j] = 1;
		else if (info->char_map[start_x][start_y] == '.')
			info->col_map->map[i][j] = 2;
		else if (info->char_map[start_x][start_y] == '#')
			info->col_map->map[i][j] = 3;
		else if (info->char_map[start_x][start_y] == '^')
			info->col_map->map[i][j] = 4;
		else if (info->char_map[start_x][start_y] == 'a')
			info->col_map->map[i][j] = 5;
		else
			info->col_map->map[i][j] = 0;
		j++;
		start_y++;
	}

	i = 0;
	j = 0;
	start_x = info->player->x - 10;
	start_y = info->player->y - 10;
	while (i < 20)
	{
		if (info->char_map[start_x][start_y] == 'C')
			info->col_map->map[i][j] = 1;
		else if (info->char_map[start_x][start_y] == '.')
			info->col_map->map[i][j] = 2;
		else if (info->char_map[start_x][start_y] == '#')
			info->col_map->map[i][j] = 3;
		else if (info->char_map[start_x][start_y] == '^')
			info->col_map->map[i][j] = 4;
		else if (info->char_map[start_x][start_y] == 'a')
			info->col_map->map[i][j] = 5;
		else
			info->col_map->map[i][j] = 0;
		i++;
		start_x++;
	}

	i = 19;
	j = 0;
	start_y = info->player->y - 10;
	while (j < 20)
	{
		if (info->char_map[end_x][start_y] == 'C')
			info->col_map->map[i][j] = 1;
		else if (info->char_map[end_x][start_y] == '.')
			info->col_map->map[i][j] = 2;
		else if (info->char_map[end_x][start_y] == '#')
			info->col_map->map[i][j] = 3;
		else if (info->char_map[end_x][start_y] == '^')
			info->col_map->map[i][j] = 4;
		else if (info->char_map[start_x][start_y] == 'a')
			info->col_map->map[i][j] = 5;
		else
			info->col_map->map[i][j] = 0;
		j++;
		start_y++;
	}

	j = 19;
	i = 0;
	start_x = info->player->x - 10;
	while (i < 20)
	{
		if (info->char_map[start_x][end_y] == 'C')
			info->col_map->map[i][j] = 1;
		else if (info->char_map[start_x][end_y] == '.')
			info->col_map->map[i][j] = 2;
		else if (info->char_map[start_x][end_y] == '#')
			info->col_map->map[i][j] = 3;
		else if (info->char_map[start_x][end_y] == '^')
			info->col_map->map[i][j] = 4;
		else if (info->char_map[start_x][start_y] == 'a')
			info->col_map->map[i][j] = 5;
		else
			info->col_map->map[i][j] = 0;
		i++;
		start_x++;
	}
/*
	i = 0;
	j = 0;
	while (i < 20)
	{
		while (j < 20)
		{
			printf("%d ", info->col_map->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}

	i = 0;
	j = 0;
	start_x = info->player->x - 10;
	start_y = info->player->y - 10;
	while(i < 20)
	{
		while (j < 20)
		{
			if (i == 10 && j == 10)
				printf("@");
			else
				printf("%c ", info->char_map[start_x + i][start_y + j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}

	printf("player (%f, %f)\n", info->player->x, info->player->y);
	printf("\n\n");*/
}
