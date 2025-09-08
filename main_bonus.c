/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:04:07 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/04 19:05:25 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_env	*env;

	env = ft_init_env(argc, argv);
	if (!env)
		ft_print_error("Error: Failed to allocate memory to env");
	ft_calc_fract(env->fract, env->window);
	ft_set_fract_draw(env->window, env->fract);
	ft_draw_img_buffer(env->window);
	mlx_mouse_hook(env->window->x_window, ft_mouse_handler, env);
	mlx_key_hook(env->window->x_window, ft_key_handler, env);
	mlx_hook(env->window->x_window, 6, 1L << 6, ft_mouse_move_handler, env);
	mlx_hook(env->window->x_window, 17, 1L << 0, ft_close_window, env);
	mlx_loop(env->window->mlx);
	ft_destroy_env(env);
}
