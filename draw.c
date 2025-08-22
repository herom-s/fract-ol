/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:46:08 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/22 19:10:08 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static void	ft_put_pixel(t_window *window, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < window->width && y >= 0 && y < window->height)
	{
		pxl = window->img->img_addr
			+ (y * window->img->size_line
				+ x * (window->img->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

void	ft_set_fract_draw(t_window *window, t_fract *fract)
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
			ft_put_pixel(window, fract->x[x], fract->y[y], fract->color[x][y]);
			y++;
		}
		x++;
	}
}
