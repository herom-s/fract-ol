/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:22:14 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/22 17:48:09 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

t_img_buffer	*ft_init_img_buffer(t_window *window)
{
	t_img_buffer	*img_buffer;

	img_buffer = malloc(sizeof(t_img_buffer));
	if (!img_buffer)
		return (NULL);
	img_buffer->img = mlx_new_image(window->mlx, window->width, window->height);
	img_buffer->img_addr = mlx_get_data_addr(img_buffer->img,
			&img_buffer->bits_per_pixel,
			&img_buffer->size_line, &img_buffer->endian);
	return (img_buffer);
}

void	*ft_destroy_img_buffer(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img->img);
	free(window->img);
	window->img = NULL;
	return (NULL);
}

void	ft_draw_img_buffer(t_window *window)
{
	mlx_put_image_to_window(window->mlx,
		window->x_window, window->img->img, 0, 0);
}
