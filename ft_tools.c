/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 09:08:35 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/02 09:10:52 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		ft_puterror(char signal)
{
	if (signal == 'a')
		exit(write(2,
			"Wrong exec. Try ./fractal [map]\n", 32));
	else if (signal == 'm')
		exit(write(2,
			"Wrong map. Try ./fractal [1 - 3]\n", 33));
	else
		exit(write(2,
			"Unknown Error\n", 14));
}

t_loader	ft_maploader(char map)
{
	if (map == '1')
		return (1);
	if (map == '2')
		return (2);
	if (map == '3')
		return (3);
	ft_puterror('m');
	return (0);
}

void		ft_borderset(t_fractal *fractal, char starter)
{
	if (fractal->map == 1)
	{
		LIMITS.y[1] =
		LIMITS.x[1] = 1.01;
		LIMITS.x[0] = -2.01;
		LIMITS.y[0] = -1.02;
	}
	else
	{
		LIMITS.x[1] = 2.3;
		LIMITS.y[1] = 2.01;
		LIMITS.x[0] = -2.3;
		LIMITS.y[0] = -2.01;
	}
	if (starter == 'y')
	{
		fractal->depth = 50;
		fractal->breaker = 0;
		fractal->current_color = 986895;
	}
}
