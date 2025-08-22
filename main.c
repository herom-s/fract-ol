/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:53:49 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/22 19:15:09 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	main(void)
{
	t_window	*window;
	t_fract		*fract;

	window = ft_init_window(1920, 1080, "fractol");
	fract = ft_init_fract(window);

	ft_set_fract_draw(window, fract);
	ft_draw_img_buffer(window);
	mlx_loop(window->mlx);
	ft_destroy_window(window);
}
