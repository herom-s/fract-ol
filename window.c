/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:11:13 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/01 18:41:59 by hermarti         ###   ########.fr       */
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
		ft_print_error("Error: failed window memory allocation\n");
	window->width = width;
	window->height = height;
	window->need_redraw = 1;
	window->mlx = mlx_init();
	window->x_window = mlx_new_window(window->mlx, window->width,
			window->height, window_name);
	window->img = ft_init_img_buffer(window);
	if (!window->img)
	{
		ft_destroy_window(window);
		ft_print_error("Error: failed window image memory allocation\n");
	}
	return (window);
}

void	*ft_destroy_window(t_window *window)
{
	ft_destroy_img_buffer(window);
	mlx_destroy_window(window->mlx, window->x_window);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	free(window);
	window = NULL;
	return (NULL);
}

int	ft_close_window(t_env *env)
{
	mlx_loop_end(env->window->mlx);
	return (0);
}
