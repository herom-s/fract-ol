/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:35:50 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 01:08:53 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <stdlib.h>

static void	ft_zoom_in_pos(t_env *env, int x, int y, double zoom)
{
	double	mpx;
	double	mpy;

	env->window->need_redraw = 1;
	mpx = env->fract->x_offset + (x - env->window->width / 2.0) * (4.0
			/ env->fract->zoom) / env->window->width;
	mpy = env->fract->y_offset - (y - env->window->height / 2.0) * (4.0
			/ env->fract->zoom) / env->window->height;
	env->fract->zoom *= zoom;
	env->fract->x_offset = mpx - (x - env->window->width / 2.0) * (4.0
			/ env->fract->zoom) / env->window->width;
	env->fract->y_offset = mpy + (y - env->window->height / 2.0) * (4.0
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

int	ft_mouse_move_handler(int x, int y, t_env *env)
{
	static int	last_x = -1;
	static int	last_y = -1;

	if (abs(x - last_x) < 10 && abs(y - last_y) < 10)
		return (0);
	env->window->mx = x;
	env->window->my = y;
	last_x = x;
	last_y = y;
	if ((env->fract->type == JULIA_SET || env->fract->type == JULIA3D_SET)
		&& env->fract->need_zoom == 0)
	{
		env->window->need_redraw = 1;
		env->fract->px = (env->window->mx - env->window->width / 2.0) * (4.0
				/ env->fract->zoom) / env->window->width;
		env->fract->py = (env->window->my - env->window->height / 2.0) * (4.0
				/ env->fract->zoom) / env->window->height;
		if (env->window->need_redraw)
		{
			ft_calc_fract(env->fract, env->window);
			ft_set_fract_draw(env->window, env->fract);
			ft_draw_img_buffer(env->window);
		}
	}
	return (0);
}
