/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_fract_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:45:20 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/05 16:12:34 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <math.h>

static int	ft_approx_eq_double(double a, double b)
{
	if (fabs(a - b) < 1e-9)
		return (1);
	else
		return (0);
}

static int	ft_check_period(double zx, double zy, double *iter, double max_iter)
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

int	ft_burning_ship_calc_fract_points(t_fract *fract, double x, double y)
{
	double	zx;
	double	zy;
	double	zx2;
	double	zy2;
	double	iter;

	iter = 0;
	zy2 = 0;
	zx2 = 0;
	zx = 0.0;
	zy = 0.0;
	while (zx2 + zy2 < 4.0 && iter < fract->max_iter)
	{
		zy = fabs(2 * zx * zy) - y;
		zx = zx2 - zy2 + x;
		zx2 = zx * zx;
		zy2 = zy * zy;
		iter++;
		if (ft_check_period(zx, zy, &iter, fract->max_iter))
			break ;
	}
	iter = (iter + 1) - log(log(sqrt(zx2 + zy2))) / log(2.0);
	return (fract->get_color[fract->color_id](fract, iter));
}
