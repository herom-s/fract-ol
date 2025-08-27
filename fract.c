/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:22:06 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/26 18:28:54 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

t_fract	*ft_init_fract(t_window *window, e_fract_type type, double px,
		double py)
{
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	if (!fract)
		return (NULL);
	fract->color = alloc_color(window);
	if (!fract->color)
		return (ft_detroy_fract(fract));
	fract->width = window->width;
	fract->height = window->height;
	fract->zoom = 1.0;
	fract->x_offset = 0.0;
	fract->y_offset = 0.0;
	fract->type = type;
	fract->pcx = 0;
	fract->pcy = 0;
	fract->px = px;
	fract->py = py;
	return (fract);
}

void	*ft_detroy_fract(t_fract *fract)
{
	if (fract->color)
		ft_free_color(fract);
	free(fract);
	fract = NULL;
	return (NULL);
}

static void	ft_calc_coordinate(t_fract *fract, t_window *window, int x, int y)
{
	fract->pcx = (x - window->width / 2.0) * (4.0 / fract->zoom) / window->width
		+ fract->x_offset;
	fract->pcy = (y - window->height / 2.0) * (4.0 / fract->zoom)
		/ window->height + fract->y_offset;
}

static void	ft_calc_pixel_color(t_fract *fract, int max_iter, int x, int y)
{
	if (fract->type == MALDEBROT_SET)
	{
		fract->color[x][y] = ft_maldebrot_calc_fract_points(fract, fract->pcx,
				fract->pcy, max_iter);
	}
	else if (fract->type == JULIA_SET)
	{
		fract->color[x][y] = ft_julia_calc_fract_points(fract, fract->pcx,
				fract->pcy, max_iter);
	}
}

void	ft_calc_fract(t_fract *fract, t_window *window, int max_iter)
{
	int	x;
	int	y;

	x = 0;
	while (x < window->width)
	{
		y = 0;
		while (y < window->height)
		{
			ft_calc_coordinate(fract, window, x, y);
			ft_calc_pixel_color(fract, max_iter, x, y);
			y++;
		}
		x++;
	}
}
