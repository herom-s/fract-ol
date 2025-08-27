/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maldebrot_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:00:47 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/26 18:27:54 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int	ft_approx_eq_double(double a, double b)
{
	if (fabs(a - b) < 1e-9)
		return (1);
	else
		return (0);
}

static int	ft_get_color_smooth(double iter, int max_iter)
{
	double	v;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	v = log(iter + 1) / log(max_iter + 1);
	r = (int)(9 * (1 - v) * v * v * v * 255);
	g = (int)(15 * (1 - v) * (1 - v) * v * v * 255);
	b = (int)(8.5 * (1 - v) * (1 - v) * (1 - v) * v * 255);
	return ((r << 16) | (g << 8) | b);
}

int	ft_maldebrot_calc_fract_points(t_fract *fract, double x, double y,
		int max_iter)
{
	double	zx;
	double	zy;
	double	zx2;
	double	zy2;
	double	xold;
	double	yold;
	int		iter;
	int		period;

	period = 0;
	iter = 0;
	zy2 = 0;
	zx2 = 0;
	zx = fract->px;
	zy = fract->py;
	while (zx2 + zy2 < 4.0 && iter < max_iter)
	{
		zy = 2 * zx * zy + y;
		zx = zx2 - zy2 + x;
		zx2 = zx * zx;
		zy2 = zy * zy;
		iter++;
		if (ft_approx_eq_double(zx, xold) && ft_approx_eq_double(zy, yold))
		{
			iter = max_iter;
			break ;
		}
		period++;
		if (period > 20)
		{
			period = 0;
			xold = zx;
			yold = zy;
		}
	}
	return (ft_get_color_smooth((double)iter, max_iter));
}
