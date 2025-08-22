/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:00:47 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/22 19:14:02 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);

}

void	ft_calc_fract_points(t_fract *fract, int x, int y, int max_iter)
{
	int	x2;
	int	y2;
	int	iter;

	x2 = 0;
	y2 = 0;
	iter = 0;
	while (x2 + y2 <= 4 && iter < max_iter)
	{
		fract->y[y] = 2 * fract->x[x] * fract->y[y] + fract->c->y[y];
		fract->x[x] = x2 - y2 + fract->c->x[x];
		x2 = fract->x[x] * fract->x[x];
		y2 = fract->y[y] * fract->y[y];
		iter++;
	}
	fract->color[x][y] = iter;
}
