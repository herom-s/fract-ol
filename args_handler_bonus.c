/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:31:07 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 02:22:14 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"

static int	ft_set_fract(t_fract_type type, t_env *env, char **argv)
{
	env->fract->type = type;
	if (type == JULIA_SET)
	{
		env->fract->px = ft_atof(argv[2]);
		env->fract->py = ft_atof(argv[3]);
		env->fract->need_zoom = 1;
	}
	else if (type == MALDEBROT3D_SET)
		env->fract->power = ft_atof(argv[2]);
	else if (type == JULIA3D_SET)
	{
		env->fract->px = ft_atof(argv[2]);
		env->fract->py = ft_atof(argv[3]);
		env->fract->pz = ft_atof(argv[4]);
		env->fract->need_zoom = 1;
	}
	return (1);
}

int	ft_args_handler(t_env *env, int argc, char **argv)
{
	if ((ft_strcmp(argv[1], "mandelbrot") == 0)
		&& ft_check_args_count(MALDEBROT_SET, env, argc))
		return (ft_set_fract(MALDEBROT_SET, env, argv));
	if (ft_strcmp(argv[1], "julia") == 0 && ft_check_args_julia(env, argc,
			argv))
		return (ft_set_fract(JULIA_SET, env, argv));
	if ((ft_strcmp(argv[1], "burning_ship") == 0)
		&& ft_check_args_count(BURNING_SHIP_SET, env, argc))
		return (ft_set_fract(BURNING_SHIP_SET, env, argv));
	if (ft_strcmp(argv[1], "mandelbrot3d") == 0
		&& ft_check_args_mandelbrot3d(env, argc, argv))
		return (ft_set_fract(MALDEBROT3D_SET, env, argv));
	if (ft_strcmp(argv[1], "julia3d") == 0 && ft_check_args_julia3d(env, argc,
			argv))
		return (ft_set_fract(JULIA3D_SET, env, argv));
	return (0);
}
