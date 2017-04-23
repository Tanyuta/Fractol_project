/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 09:09:05 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/02 09:10:40 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_keypress(t_fractal *fractal, int key)
{
	if (key == 125)
	{
		LIMITS.y[1] += 0.05;
		LIMITS.y[0] += 0.05;
	}
	if (key == 126)
	{
		LIMITS.y[1] -= 0.05;
		LIMITS.y[0] -= 0.05;
	}
	if (key == 124)
	{
		LIMITS.x[1] += 0.05;
		LIMITS.x[0] += 0.05;
	}
	if (key == 123)
	{
		LIMITS.x[1] -= 0.05;
		LIMITS.x[0] -= 0.05;
	}
	ft_start_to_draw(fractal);
}

int		ft_reupdate(int key, t_fractal *f)
{
	if (key == 125 || key == 126 || key == 124 || key == 123)
		ft_keypress(f, key);
	if (key == 121)
		ft_out_n_in_zoom(5, WINDOW_X >> 1, WINDOW_Y >> 1, f);
	if (key == 116)
		ft_out_n_in_zoom(4, WINDOW_X >> 1, WINDOW_Y >> 1, f);
	if (key == 53)
		exit(1);
	if (key == 69)
	{
		f->depth += 15;
		ft_start_to_draw(f);
	}
	if (key == 49)
	{
		ft_borderset(f, 'n');
		ft_start_to_draw(f);
	}
	if (key == 78)
	{
		f->depth += 15;
		ft_start_to_draw(f);
	}
	return (1);
}

int		ft_rezooming(t_fractal *f)
{
	(f->j_flag2 == 1) ? ft_out_n_in_zoom(5, 400, 400, f) : 0;
	(f->j_flag2 == 2) ? ft_out_n_in_zoom(4, 400, 400, f) : 0;
	return (1);
}

int		ft_cross_out(void)
{
	exit(1);
}

int		ft_key_initializers(t_fractal *f)
{
	void *w;
	void *mlx;

	w = f->win_pointer;
	mlx = f->mlx;
	mlx_key_hook(w, ft_reupdate, f);
	mlx_mouse_hook(w, ft_mouse_shift, f);
	mlx_hook(w, 6, 0, ft_mouse_flux, f);
	mlx_hook(w, 17, 0, ft_cross_out, (void*)0);
	mlx_hook(w, 2, 5, ft_colorage, f);
	mlx_loop_hook(mlx, ft_rezooming, f);
	mlx_loop(mlx);
	return (1);
}
