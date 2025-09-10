/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_fract_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:45:20 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 02:38:36 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <math.h>

static int	ft_approx_eq_float(float a, float b)
{
	if (fabsf(a - b) < 1e-9)
		return (1);
	else
		return (0);
}

static int	ft_check_period(float zx, float zy, float *iter, float max_iter)
{
	static float	xold = 0.0f;
	static float	yold = 0.0f;
	static int		period = 0;

	if (ft_approx_eq_float(zx, xold) && ft_approx_eq_float(zy, yold))
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

int	ft_burning_ship_calc_fract_points(t_fract *fract, float x, float y)
{
	float	zx;
	float	zy;
	float	zx2;
	float	zy2;
	float	iter;

	iter = 0.0f;
	zy2 = 0.0f;
	zx2 = 0.0f;
	zx = 0.0f;
	zy = 0.0f;
	while (zx2 + zy2 < 4.0f && iter < fract->max_iter)
	{
		zy = fabsf(2.0f * zx * zy) - y;
		zx = zx2 - zy2 + x;
		zx2 = zx * zx;
		zy2 = zy * zy;
		iter++;
		if (ft_check_period(zx, zy, &iter, fract->max_iter))
			break ;
	}
	iter = (iter + 1.0f) - logf(logf(sqrtf(zx2 + zy2))) / logf(2.0f);
	return (fract->get_color[fract->color_id](fract, iter));
}
