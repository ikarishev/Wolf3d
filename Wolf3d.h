/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:03:18 by ikarishe          #+#    #+#             */
/*   Updated: 2018/09/06 14:53:09 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdlib.h>
# include "minilibx2/mlx.h"
# include "libft/libft.h"
# include "keys.h"
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
#include <stdio.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TICK_MS 100000

typedef struct	s_my_clock
{
	int		need_update;
	clock_t	last_time;
}				t_my_clock;

typedef struct	s_dim
{
	int	tex_w;
	int	tex_h;
	int	win_w;
	int	win_h;
}				t_dim;

typedef struct s_player
{
    double  x;
    double  y;
    double  z;
	double 	x_loc;
	double  y_loc;
    double  dir_x;
    double  dir_y;
    double  move_speed;
    double  rot_speed;
    int     draw_hand;
}               t_player;

typedef struct s_ray
{
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    int     map_x;
    int     map_y;
    int     side;
    int     step_x;
    int     step_y;
    double  side_dist_x;
    double  side_dist_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  prep_wall_dist;
    int     hit;
}               t_ray;

typedef struct s_plane
{
    double x;
    double y;
}               t_plane;

typedef struct s_line
{
    int     tex_x;
    double  wall_x;
    int     line_height;
    int     draw_start;
    int     draw_end;
    int     def_color;
}               t_line;

typedef	struct	s_mouse
{
	int		min_x;
	int		max_x;
	int		last_dif_x;
	int		last_x;
	int		last_y;
	int		x;
	int		y;
}				t_mouse;

typedef struct	s_map
{
	int		height;
	int		width;
	int		map[20][20];
}				t_map;

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	void		*display_img;
	void		*skybox_img;
	void		*sea_tex;
	void		*tree1_tex;
	void		*mount1_tex;
	void		*road1_tex;
	void		*sand1_tex;
	void		*mountain_floor;

	t_dim		*dim;
	t_player	*player;
	t_ray		*ray;
	t_plane		*plane;
	t_line		*line;
	t_my_clock	*clock;
	t_mouse		*mouse;

	char		**char_map;

	t_keys		*keys;

	char		*level;

	t_map		*col_map;
	t_map		*tex_map;

}				t_info;

typedef	struct	s_image
{
	void	*image;
	char	*ptr;
	int		bpp;
}				t_image;

void			set_up_mlx_stuff(t_info *info);
void			init_info(t_info *info);
void			free_info(t_info *info);
int				exit_hook(void *in);
void			end_program(t_info *info);
//int				my_key_funct(int keycode, void *in);
int				key_press(int keycode, void *in);
int				key_release(int keycode, void *in);


int				hook_mousemove(int x, int y, t_info *info);
void			check_need_update(t_info *info);
void			image_set_pixel(t_image *image, int x, int y, int color);
int				image_get_pxl(t_image *image, int x, int y, int tex_width);
int				image_get_pxl2(t_image *image, int x, int y, int tex_width);
void			fill_skybox(t_info *info);
void			draw_sky_box(t_info *info);
//void			read_maps(t_info *info);
int				read_map(char *filename, t_info *info, t_map *map);



void			raycast(t_info *info);
void    draw_line(int x, int draw_start, int draw_end, t_info *info);

int     dull_color(int color);
int     dull_color_a_little(int color);
int     fade_color(int color, t_info *info);
void	move_player(t_info *info);


void    make_char_map(t_info *info);
void    read_char_map(t_info *info);
void    char_map_to_local(t_info *info);
void    char_map_to_local2(t_info *info, int num);

void	load_textures(t_info *info);

void	rotate_right(t_info *info);
void	rotate_left(t_info *info);

void	init_player(t_info *info);
void	init_plane(t_info *info);

#endif
