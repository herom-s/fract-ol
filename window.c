/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:11:13 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/22 15:57:59 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

t_window	*ft_init_window(int width, int height, char *window_name)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->width = width;
	window->height = height;
	window->need_redraw = 0;
	window->mlx = mlx_init();
	window->x_window = mlx_new_window(window->mlx,
			window->width, window->height, window_name);
	window->img = ft_init_img_buffer(window);
	return (window);
}

void	ft_destroy_window(t_window *window)
{
	ft_destroy_img_buffer(window);
	mlx_destroy_window(window->mlx, window->x_window);
	free(window);
	window = NULL;
}
