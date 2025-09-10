/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:32:19 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 03:06:46 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"
#include <stdlib.h>

t_fract	*ft_init_fract(t_window *window, t_fract_type type, float px, float py)
{
	t_fract	*fract;

	fract = ft_calloc(1, sizeof(t_fract));
	if (!fract)
		return (NULL);
	fract->color = ft_alloc_color(window);
	if (!fract->color)
		return (ft_detroy_fract(fract));
	fract->max_iter = 100;
	fract->width = window->width;
	fract->height = window->height;
	fract->zoom = 1.0f;
	fract->type = type;
	fract->px = px;
	fract->py = py;
	ft_set_get_color(fract);
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

void	ft_calc_coordinate(t_fract *fract, t_window *window, int x, int y)
{
	fract->pcx = (x - window->width / 2.0f) * (4.0f / fract->zoom)
		/ window->width + fract->x_offset;
	fract->pcy = -(y - window->height / 2.0f) * (4.0f / fract->zoom)
		/ window->height + fract->y_offset;
}

static void	ft_calc_pixel_color(t_fract *fract, int x, int y)
{
	if (fract->type == MALDEBROT_SET)
	{
		fract->color[x][y] = ft_mandelbrot_calc_fract_points(fract, fract->pcx,
				fract->pcy);
	}
	else if (fract->type == JULIA_SET)
	{
		fract->color[x][y] = ft_julia_calc_fract_points(fract, fract->pcx,
				fract->pcy);
	}
	else if (fract->type == BURNING_SHIP_SET)
	{
		fract->color[x][y] = ft_burning_ship_calc_fract_points(fract,
				fract->pcx, fract->pcy);
	}
	else if (fract->type == MALDEBROT3D_SET)
	{
		fract->color[x][y] = ft_mandelbrot3d_calc_fract_points(fract,
				fract->pcx, fract->pcy);
	}
	else if (fract->type == JULIA3D_SET)
	{
		fract->color[x][y] = ft_julia3d_calc_fract_points(fract, fract->pcx,
				fract->pcy);
	}
}

void	ft_calc_fract(t_fract *fract, t_window *window)
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
			ft_calc_pixel_color(fract, x, y);
			y++;
		}
		x++;
	}
}
