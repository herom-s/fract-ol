/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:35:50 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/04 19:36:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_zoom_in_pos(t_env *env, int x, int y, double zoom)
{
	double	mouse_pcx;
	double	mouse_pcy;

	env->window->need_redraw = 1;
	mouse_pcx = env->fract->x_offset + (x - env->window->width / 2.0) * (4.0
			/ env->fract->zoom) / env->window->width;
	mouse_pcy = env->fract->y_offset - (y - env->window->height / 2.0) * (4.0
			/ env->fract->zoom) / env->window->height;
	env->fract->zoom *= zoom;
	env->fract->x_offset = mouse_pcx - (x - env->window->width / 2.0) * (4.0
			/ env->fract->zoom) / env->window->width;
	env->fract->y_offset = mouse_pcy + (y - env->window->height / 2.0) * (4.0
			/ env->fract->zoom) / env->window->height;
	ft_calc_coordinate(env->fract, env->window, x, y);
}

int	ft_mouse_handler(int mousecode, int x, int y, t_env *env)
{
	if (mousecode == 4)
		ft_zoom_in_pos(env, x, y, 1.1);
	else if (mousecode == 5)
		ft_zoom_in_pos(env, x, y, 0.9);
	if (env->window->need_redraw)
	{
		ft_calc_fract(env->fract, env->window);
		ft_set_fract_draw(env->window, env->fract);
		ft_draw_img_buffer(env->window);
	}
	return (0);
}
