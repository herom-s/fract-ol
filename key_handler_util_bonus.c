/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_util_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:50:36 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/09 21:31:37 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
