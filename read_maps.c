/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:01:39 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/03 15:20:02 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* REDO this to allow arbitrary map sizes... like you did in fdf */


#include "Wolf3d.h"
#include <stdio.h>

void	err_exit(void)
{
	write(1, "Could not open file\n", 20);
	exit (0);
}

int		make_map(int fd, int height, int width, t_info *info, t_map *map)
{
	int i;
	int j;
	char *str;
	(void)info;

	i = 0;
	j = 0;

//	info->map->map = malloc(sizeof(int) * height * width +
//			sizeof(int*) * height * width);

	while (i < height)
	{
		get_next_line(fd, &str);
		j = 0;
		while (j < width)
		{
			map->map[i][j] = ft_atoi(str + 3 * j);
			j++;
		}
		i++;
		free(str);
	}
	return (0);
}

int		read_map(char *filename, t_info *info, t_map *map)
{
	int fd;
	int height;
	int width;
	char *str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		err_exit();
	get_next_line(fd, &str);
	height = ft_atoi(str);
	map->height = height;
	free(str);
	get_next_line(fd, &str);
	width = ft_atoi(str);
	free(str);
	map->width = width;
	make_map(fd, height, width, info, map);
	return (0);
}
