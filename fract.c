/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:22:06 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/22 19:17:33 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static int	**alloc_color(t_window *window)
{
	int	i;
	int	**color;

	i = 0;
	color = malloc(window->width * sizeof(int *));
	if (!color)
		return (NULL);
	while (i < window->width)
	{
		color[i] = malloc(window->height * sizeof(int));
		if (!color[i])
		{
			while (i > 0)
			{
				free(color[i]);
				i++;
			}
			free(color);
			return (NULL);
		}
		i++;
	}
	return (color);
}

t_fract	*ft_init_fract(t_window *window)
{
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	if (!fract)
		return (NULL);
	fract->z = ft_init_complex(window->width, window->height);
	fract->c = ft_init_complex(window->width, window->height);
	fract->x = malloc(window->width * sizeof(int));
	fract->y = malloc(window->height * sizeof(int));
	fract->color = alloc_color(window);
	if (!fract->z || !fract->c || !fract->x || !fract->y || !fract->color)
	{
		ft_detroy_fract(fract);
		return (NULL);
	}
	fract->zoom = 1.0;
	fract->x_offeset = 0.0;
	fract->y_offeset = 0.0;
	fract->type = 0;
	return (fract);
}

void	ft_detroy_fract(t_fract *fract)
{
	if (fract->z)
		ft_destroy_complex(fract->z);
	if (fract->c)
		ft_destroy_complex(fract->c);
	if (fract->x)
		free(fract->x);
	if (fract->y)
		free(fract->y);
	free(fract);
}

void	ft_set_fract_c(t_fract *fract, t_window *window)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < window->width)
	{
		y = 0;
		while (y < window->height)
		{
			fract->c->x[x] = x - ((double) window->width / 2)
				* fract->zoom + fract->x_offeset;
			fract->c->y[y] = y - ((double) window->height / 2)
				* fract->zoom + fract->y_offeset;
			y++;
		}
		x++;
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
			ft_calc_fract_points(fract, x, y, max_iter);
			y++;
		}
		x++;
	}
}
