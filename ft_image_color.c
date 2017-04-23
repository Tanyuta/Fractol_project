/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 09:08:46 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/02 09:10:45 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		ft_choose_your_color(int paint, t_fractal *fractal)
{
	DRAW.rgb[0] = (paint >> 16);
	DRAW.rgb[1] = (paint >> 8) - (DRAW.rgb[0] << 8);
	DRAW.rgb[2] = paint - (DRAW.rgb[0] << 16) - (DRAW.rgb[1] << 8);
}

t_loader	ft_mlx_image(t_fractal *fractal)
{
	TOIMAGE.longev =
	TOIMAGE.pixels =
	TOIMAGE.border = 0;
	TOIMAGE.addr = mlx_get_data_addr((
		TOIMAGE.map = mlx_new_image(fractal->mlx, WINDOW_X, WINDOW_Y)),
	&TOIMAGE.pixels, &TOIMAGE.longev, &TOIMAGE.border);
	return (0);
}

void		ft_putcolor(int x, int y, t_fractal *fractal)
{
	int point;

	if (x < WINDOW_Y * WINDOW_X * 4)
	{
		point = (x << 2) + y * TOIMAGE.longev;
		TOIMAGE.addr[point + 2] = DRAW.rgb[0];
		TOIMAGE.addr[point + 1] = DRAW.rgb[1];
		TOIMAGE.addr[point] = DRAW.rgb[2];
	}
}
