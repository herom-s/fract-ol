/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:34:46 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/04 19:34:54 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	change_iter_handler(int keycode, t_env *env)
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
		if (env->fract->max_iter < 0)
			env->fract->max_iter = 10;
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
	change_iter_handler(keycode, env);
	if (env->window->need_redraw)
	{
		ft_calc_fract(env->fract, env->window);
		ft_set_fract_draw(env->window, env->fract);
		ft_draw_img_buffer(env->window);
	}
	return (0);
}
