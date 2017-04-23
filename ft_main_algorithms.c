/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 09:08:41 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/02 09:10:49 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

long		ft_mandelbrot(t_fractal *fractal)
{
	double	real;
	double	imag;
	double	temp;
	long	result;

	result = 0;
	real = 0;
	imag = 0;
	while (result < fractal->depth)
	{
		temp = (real * real) - (imag * imag);
		imag = 2 * real * imag + DRAW.y;
		real = temp + DRAW.x;
		if ((real * real + imag * imag) > 4)
			break ;
		result++;
	}
	return (result);
}

long		ft_burningship(t_fractal *fractal)
{
	double	real;
	double	imag;
	double	temp;
	long	result;

	result = 0;
	real = 0;
	imag = 0;
	while (result < fractal->depth)
	{
		temp = (real * real - imag * imag);
		imag = 2 * fabs(real * imag) + DRAW.y;
		real = temp + DRAW.x;
		if ((real * real + imag * imag) > 4)
			break ;
		result++;
	}
	return (result);
}

long		ft_julia(t_fractal *fractal)
{
	double	real;
	double	imag;
	double	temp;
	long	result;

	real = DRAW.x;
	imag = DRAW.y;
	result = 0;
	while (result < fractal->depth)
	{
		temp = (real * real - imag * imag);
		imag = 2 * real * imag + DRAW.julia[1];
		real = temp + DRAW.julia[0];
		if ((real * real + imag * imag) > 4)
			break ;
		result++;
	}
	return (result);
}

long		ft_choose_your_algo(t_fractal *fractal)
{
	long iters;

	iters = 0;
	if (fractal->map == 1)
		iters = ft_mandelbrot(fractal);
	else if (fractal->map == 2)
		iters = ft_burningship(fractal);
	else if (fractal->map == 3)
		iters = ft_julia(fractal);
	return (iters);
}
