/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_util_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:50:36 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 01:45:36 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_set_fract_change(t_fract_type type, t_env *env)
{
	env->window->need_redraw = 1;
	env->fract->type = type;
	if (type == JULIA_SET || type == JULIA3D_SET)
	{
		env->fract->need_zoom = 0;
		env->fract->px = (env->window->mx - env->window->width / 2.0) * (4.0
				/ env->fract->zoom) / env->window->width;
		env->fract->py = (env->window->my - env->window->height / 2.0) * (4.0
				/ env->fract->zoom) / env->window->height;
		env->fract->pz = 0.0;
	}
	else if (type == MALDEBROT3D_SET)
	{
		env->fract->power = 2.0;
	}
}

void	ft_change_fract_handler(int keycode, t_env *env)
{
	if (keycode == 49)
		ft_set_fract_change(MALDEBROT_SET, env);
	else if (keycode == 50)
		ft_set_fract_change(JULIA_SET, env);
	else if (keycode == 51)
		ft_set_fract_change(BURNING_SHIP_SET, env);
	else if (keycode == 52)
		ft_set_fract_change(MALDEBROT3D_SET, env);
	else if (keycode == 53)
		ft_set_fract_change(JULIA3D_SET, env);
}

void	ft_rotate_3dfract_handler(int keycode, t_env *env)
{
	if (env->fract->type != MALDEBROT3D_SET && env->fract->type != JULIA3D_SET)
		return ;
	if (keycode == 117)
	{
		env->window->need_redraw = 1;
		env->fract->x_rotation += 0.1 / env->fract->zoom;
	}
	else if (keycode == 106)
	{
		env->window->need_redraw = 1;
		env->fract->x_rotation -= 0.1 / env->fract->zoom;
	}
	else if (keycode == 104)
	{
		env->window->need_redraw = 1;
		env->fract->y_rotation -= 0.1 / env->fract->zoom;
	}
	else if (keycode == 107)
	{
		env->window->need_redraw = 1;
		env->fract->y_rotation += 0.1 / env->fract->zoom;
	}
}
