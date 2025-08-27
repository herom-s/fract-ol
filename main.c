/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:53:49 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/26 18:51:43 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	main(void)
{
	t_window	*window;
	t_fract		*fract;

	window = ft_init_window(1920, 1080, "fractol");
	if (!window)
		return (1);
	fract = ft_init_fract(window, MALDEBROT_SET, 0, 0);
	ft_calc_fract(fract, window, 1000);
	ft_set_fract_draw(window, fract);
	ft_draw_img_buffer(window);
	mlx_loop(window->mlx);
	ft_detroy_fract(fract);
	ft_destroy_window(window);
}
