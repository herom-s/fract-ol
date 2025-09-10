/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:34:46 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 01:39:26 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"

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

static void	ft_reset_fract_handler(int keycode, t_env *env)
{
	if (keycode == 122)
	{
		env->window->need_redraw = 1;
		env->fract->zoom = 1.0f;
		env->fract->x_offset = 0.0f;
		env->fract->y_offset = 0.0f;
		env->fract->z_offset = 0.0f;
		env->fract->x_rotation = 0.0f;
		env->fract->y_rotation = 0.0f;
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
	ft_reset_fract_handler(keycode, env);
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
