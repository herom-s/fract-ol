/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:34:46 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/09 18:51:54 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

static void	ft_change_fract_handler(int keycode, t_env *env)
{
	if (keycode == 49)
	{
		env->window->need_redraw = 1;
		env->fract->type = MALDEBROT_SET;
	}
	else if (keycode == 50)
	{
		env->window->need_redraw = 1;
		env->fract->need_zoom = 0;
		env->fract->type = JULIA_SET;
		env->fract->px = (env->window->mx - env->window->width / 2.0) * (4.0
				/ env->fract->zoom) / env->window->width;
		env->fract->py = (env->window->my - env->window->height / 2.0) * (4.0
				/ env->fract->zoom) / env->window->height;
	}
	else if (keycode == 51)
	{
		env->window->need_redraw = 1;
		env->fract->type = BURNING_SHIP_SET;
	}
}

static void	ft_change_fract_color_shift(int keycode, t_env *env)
{
	if (keycode == 101)
	{
		env->window->need_redraw = 1;
		env->fract->color_shift += 0.5;
		if (env->fract->color_shift >= 10)
			env->fract->color_shift = 0.5;
	}
	else if (keycode == 114)
	{
		env->window->need_redraw = 1;
		env->fract->color_shift -= 0.5;
		if (env->fract->color_shift <= 0)
			env->fract->color_shift = 0.5;
	}
}

static void	ft_move_in_fract_handler(int keycode, t_env *env)
{
	if (keycode == 65362 || keycode == 119)
	{
		env->window->need_redraw = 1;
		env->fract->y_offset += 0.1 / env->fract->zoom;
	}
	else if (keycode == 65364 || keycode == 115)
	{
		env->window->need_redraw = 1;
		env->fract->y_offset -= 0.1 / env->fract->zoom;
	}
	else if (keycode == 65361 || keycode == 97)
	{
		env->window->need_redraw = 1;
		env->fract->x_offset -= 0.1 / env->fract->zoom;
	}
	else if (keycode == 65363 || keycode == 100)
	{
		env->window->need_redraw = 1;
		env->fract->x_offset += 0.1 / env->fract->zoom;
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
	ft_change_fract_handler(keycode, env);
	ft_change_fract_color_shift(keycode, env);
	ft_move_in_fract_handler(keycode, env);
	ft_rotate_3dfract_handler(keycode, env);
	if (env->window->need_redraw)
	{
		ft_calc_fract(env->fract, env->window);
		ft_set_fract_draw(env->window, env->fract);
		ft_draw_img_buffer(env->window);
	}
	return (0);
}
