/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluation_of_coords.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 09:09:09 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/02 09:10:34 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double		ft_evaluation(t_fractal *fractal, double x, double y, char coord)
{
	double result;

	if (coord == 'x')
	{
		result = ((LIMITS.x[1]
		- LIMITS.x[0]) / WINDOW_X) * x
		+ LIMITS.x[0];
	}
	else
	{
		result = ((LIMITS.y[1]
		- LIMITS.y[0]) / WINDOW_Y) * y
		+ LIMITS.y[0];
	}
	return (result);
}

int			ft_colorage(int keycode, t_fractal *fractal)
{
	if (keycode == 12)
	{
		fractal->current_color += 100;
		ft_start_to_draw(fractal);
	}
	return (1);
}

int			ft_mouse_flux(int x, int y, t_fractal *fractal)
{
	if (!fractal->jflag && (fractal->map == 3))
	{
		DRAW.julia[0] = ft_evaluation(fractal, x, y, 'x');
		DRAW.julia[1] = ft_evaluation(fractal, x, y, 'y');
		ft_start_to_draw(fractal);
	}
	return (1);
}

int			ft_out_n_in_zoom(int key, int x, int y, t_fractal *fractal)
{
	double m;
	double rx;
	double iy;

	rx = ft_evaluation(fractal, x, y, 'x');
	iy = ft_evaluation(fractal, x, y, 'y');
	if (key == 4)
		m = 0.9;
	else
		m = 1.1;
	LIMITS.x[1] = m * LIMITS.x[1] + (1 - m) * rx;
	LIMITS.x[0] = m * LIMITS.x[0] + (1 - m) * rx;
	LIMITS.y[1] = m * LIMITS.y[1] + (1 - m) * iy;
	LIMITS.y[0] = m * LIMITS.y[0] + (1 - m) * iy;
	ft_start_to_draw(fractal);
	return (1);
}

int			ft_mouse_shift(int key, int x, int y, t_fractal *f)
{
	if (key == 5 || key == 4)
		ft_out_n_in_zoom(key, x, y, f);
	if (key == 1)
		f->jflag = 0;
	if (f->jflag == 0)
		f->jflag = (key == 2) ? 1 : 0;
	return (1);
}
