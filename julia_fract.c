/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:07:44 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/01 19:16:37 by hermarti         ###   ########.fr       */
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

static int	ft_check_period(double zx, double zy, int *iter, int max_iter)
{
	static double	xold = 0.0;
	static double	yold = 0.0;
	static int		period = 0;

	if (ft_approx_eq_double(zx, xold) && ft_approx_eq_double(zy, yold))
	{
		*iter = max_iter;
		return (1);
	}
	period++;
	if (period > 20)
	{
		period = 0;
		xold = zx;
		yold = zy;
	}
	return (0);
}

int	ft_julia_calc_fract_points(t_fract *fract, double zx, double zy)
{
	double	zx2;
	double	zy2;
	int		iter;

	iter = 0;
	zy2 = zy * zy;
	zx2 = zx * zx;
	while (zx2 + zy2 < 4.0 && iter < fract->max_iter)
	{
		zy = 2 * zx * zy + fract->py;
		zx = zx2 - zy2 + fract->px;
		zy2 = zy * zy;
		zx2 = zx * zx;
		iter++;
		if (ft_check_period(zx, zy, &iter, fract->max_iter))
			return (ft_get_color_smooth((double)iter, fract->max_iter));
	}
	return (ft_get_color_smooth((double)iter, fract->max_iter));
}
