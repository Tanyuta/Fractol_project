/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 09:09:14 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/02 09:11:56 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		ft_jflag_init(int key, t_fractal *f)
{
	if (key == 13)
		f->jflag = 2;
	if (key == 14)
		f->jflag = 0;
	if (key == 1)
		f->jflag = 1;
}

void		ft_start_to_draw(t_fractal *fractal)
{
	int x_y[2];
	int result;

	result = ft_mlx_image(fractal);
	x_y[0] =
	x_y[1] = 0;
	while (x_y[0] < WINDOW_X)
	{
		DRAW.x = ft_evaluation(fractal, x_y[0], x_y[1], 'x');
		x_y[1] = 0;
		while (x_y[1] < WINDOW_Y)
		{
			DRAW.y = ft_evaluation(fractal, x_y[0], x_y[1], 'y');
			result = ft_choose_your_algo(fractal);
			(result < fractal->depth) ?
				ft_choose_your_color(fractal->current_color * result,
				fractal) : ft_choose_your_color(0, fractal);
			ft_putcolor(x_y[0], x_y[1], fractal);
			x_y[1]++;
		}
		x_y[0]++;
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->win_pointer, TOIMAGE.map, 0, 0);
	free(TOIMAGE.map);
}

int			main(int argc, char **argv)
{
	t_fractal	fractal;
	char		map;

	if (argc < 2 || argc > 2)
		ft_puterror('a');
	map = argv[1][0];
	fractal.j_flag2 = 0;
	fractal.map = ft_maploader(map);
	ft_borderset(&fractal, 'y');
	fractal.win_pointer =
	mlx_new_window((fractal.mlx = mlx_init())
	, WINDOW_X, WINDOW_Y, "Fract'ol by tprysiaz");
	ft_start_to_draw(&fractal);
	return (ft_key_initializers(&fractal));
}
