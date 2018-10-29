/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_charmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 11:55:28 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/09 12:54:06 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3d.h"

void 	make_char_map(t_info *info)
{
	void	*xpm_map;
	int		map_h;
	int		map_w;

	map_h = 100;
	map_w = 100;
	xpm_map = mlx_xpm_file_to_image(info->mlx, "maps/map.XPM", &map_w, &map_h);

	char	c_map[101][101];
	int i;
	int j;
	i = 0;
	j = 0;
	while (i < 101)
	{
		ft_bzero(c_map[i], 101);
		i++;
	}
	i = 0;
	
	int color;
	while (i < 100)
	{
		while (j < 100)
		{
			color = image_get_pxl(xpm_map, j, i, map_w);
			if (color == 16450055) //red;
				c_map[i][j] = 'X';
			else if (color == 255) //blue
				c_map[i][j] = 'C';
			else if (color == 10053171) //brown
				c_map[i][j] = '.';
			else if (color == 2227974) //green
				c_map[i][j] = '#';
			else if (color == 2228223) //cyan
				c_map[i][j] = '^';
			else
				c_map[i][j] = 'a';
			j++;
		}
		j = 0;
		i++;
	}

	int		fd;
	fd = open("maps/map_0.map", O_WRONLY | O_CREAT | O_TRUNC);
	i = 0;
	j = 0;
	while (i < 100)
	{
		while (j < 100)
		{	
			write(fd, &(c_map[i][j]), 1);
			j++;
		}
		write(fd, "\n", 1);
		j = 0;
		i++;
	}
	close (fd);
}

void	print_map(t_info *info)
{
	int i;

	i = 0;
	while (i < 100)
	{
		printf("%s\n", info->char_map[i]);
		i++;
	}
}

void	read_char_map(t_info *info)
{
	char	**new_map;
	int		i;
	int		fd;
	char	*buf;

	fd = open("maps/map_0.map", O_RDONLY);
	
	i = 0;
	new_map = (char**)malloc(sizeof(char*) * 101);
	while (i < 101)
	{
		new_map[i] = (char*)malloc(sizeof(char) * 101);
		ft_bzero(new_map[i], 101);
		i++;
	}
	i = 0;
	while (get_next_line(fd, &buf) != 0)
	{
		ft_strcpy(new_map[i], buf);
		free(buf);
		i++;
	}
	info->char_map = new_map;
	print_map(info);
}
