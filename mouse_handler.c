/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:35 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/01 20:13:56 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_handler(int mousecode, int x, int y, t_env *env)
{
	if (mousecode == 4)
	{
		env->window->need_redraw = 1;
		ft_calc_coordinate(env->fract, env->window, x, y);
		env->fract->zoom += 0.1;
	}
	else if (mousecode == 5)
	{
		env->window->need_redraw = 1;
		ft_calc_coordinate(env->fract, env->window, x, y);
		env->fract->zoom -= 0.1;
	}
	if (env->window->need_redraw)
	{
		ft_calc_fract(env->fract, env->window);
		ft_set_fract_draw(env->window, env->fract);
		ft_draw_img_buffer(env->window);
	}
	return (0);
}
