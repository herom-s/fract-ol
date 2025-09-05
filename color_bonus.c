/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:30:32 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/05 16:24:31 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <math.h>

static void	ft_clamp_color(int *r, int *g, int *b)
{
	if (*r < 0)
		*r = 0;
	else if (*r > 255)
		*r = 255;
	if (*g < 0)
		*g = 0;
	else if (*g > 255)
		*g = 255;
	if (*b < 0)
		*b = 0;
	else if (*b > 255)
		*b = 255;
}

int	ft_get_color_basic(t_fract *fract, double iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter >= fract->max_iter)
		return (0x00000000);
	t = iter / fract->max_iter;
	t = fmod(t + (fract->color_shift * 0.1), 1.0);
	r = (int)(255 * t * 0.3);
	g = (int)(255 * (1 - t) * t * 4);
	b = (int)(255 * (1 - t * 0.5));
	ft_clamp_color(&r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}

int	ft_get_color_psychedelic(t_fract *fract, double iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter >= fract->max_iter)
		return (0x000000);
	t = iter / fract->max_iter;
	t = fmod(t + (fract->color_shift * 0.1), 1.0);
	r = (int)(255 * sin(t * 16));
	g = (int)(255 * sin(t * 13 + 2));
	b = (int)(255 * sin(t * 17 + 4));
	ft_clamp_color(&r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}

int	ft_get_color_iter_shifft(t_fract *fract, double iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter >= fract->max_iter)
		return (0x000000);
	t = iter / fract->max_iter;
	t = fmod(t + (fract->color_shift * 0.1), 1.0);
	r = (int)(255 * t);
	g = (int)(255 * t);
	b = (int)(255 * t);
	ft_clamp_color(&r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}
