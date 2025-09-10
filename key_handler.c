/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:06:16 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/05 15:21:02 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_change_iter_handler(int keycode, t_env *env)
{
	if (keycode == 65451)
	{
		env->window->need_redraw = 1;
		env->fract->max_iter += 10;
	}
	else if (keycode == 65453)
	{
		env->window->need_redraw = 1;
		env->fract->max_iter -= 10;
		if (env->fract->max_iter <= 0)
			env->fract->max_iter = 10;
	}
}

static void	ft_reset_fract_handler(int keycode, t_env *env)
{
	if (keycode == 122)
	{
		env->window->need_redraw = 1;
		env->fract->zoom = 1.0f;
		env->fract->x_offset = 0.0f;
		env->fract->y_offset = 0.0f;
	}
}

int	ft_key_handler(int keycode, t_env *env)
{
	if (keycode == 65307)
		ft_close_window(env);
	else if (keycode == 113)
	{
		env->window->need_redraw = 1;
		env->fract->color_id = (env->fract->color_id + 1) % MAX_COLORS;
	}
	ft_change_iter_handler(keycode, env);
	ft_reset_fract_handler(keycode, env);
	if (env->window->need_redraw)
	{
		ft_calc_fract(env->fract, env->window);
		ft_set_fract_draw(env->window, env->fract);
		ft_draw_img_buffer(env->window);
	}
	return (0);
}
