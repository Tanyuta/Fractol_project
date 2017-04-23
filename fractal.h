/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 09:09:19 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/02 09:11:51 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# define WINDOW_X 800
# define WINDOW_Y 600
# define DRAW fractal->drawer
# define LIMITS fractal->limits
# define TOIMAGE fractal->pixeldraw

typedef unsigned char	t_loader;
typedef struct			s_limits
{
	double x[2];
	double y[2];
	double j_x[2];
	double j_y[2];
}						t_limits;

typedef struct			s_draw
{
	double	x;
	double	y;
	double	julia[2];
	int		rgb[3];
}						t_draw;

typedef struct			s_repres
{
	char	*addr;
	void	*map;
	int		longev;
	int		pixels;
	int		border;
}						t_repres;

typedef struct			s_fractal
{
	void		*mlx;
	void		*win_pointer;
	t_repres	pixeldraw;
	t_draw		drawer;
	t_limits	limits;
	int			map;
	int			breaker;
	int			current_color;
	int			jflag;
	int			j_flag2;
	int			depth;
}						t_fractal;

t_loader				ft_maploader(char map);
t_loader				ft_mlx_image(t_fractal *fractal);
void					ft_puterror(char signal);
void					ft_borderset(t_fractal *fractal, char starter);
void					ft_start_to_draw(t_fractal *f);
int						ft_key_initializers(t_fractal *f);
double					ft_evaluation(t_fractal *fractal,
	double x, double y, char coord);
long					ft_choose_your_algo(t_fractal *fractal);
void					ft_putcolor(int x, int y, t_fractal *fractal);
void					ft_choose_your_color(int paint, t_fractal *fractal);

int						ft_out_n_in_zoom(int key,
	int x, int y, t_fractal *fractal);
int						ft_colorage(int key, t_fractal *fractal);
int						ft_key_initializers(t_fractal *f);
int						ft_mouse_flux(int x, int y, t_fractal *fractal);
int						ft_mouse_shift(int key, int x, int y, t_fractal *f);

#endif
