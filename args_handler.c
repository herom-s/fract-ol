/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:33:12 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/01 19:12:10 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	ft_print_arg_help(void)
{
	ft_printf("Usage: fractol [FRACTAL_TYPE] [OPTIONS]\n\n");
	ft_printf("FRACTAL TYPES:\n");
	ft_printf("  mandelbrot    Generate Mandelbrot set\n");
	ft_printf("  julia         Generate Julia set \
(requires c_real c_imag parameters)\n");
	ft_printf("OPTIONS:\n");
	ft_printf("  -h, --help    Show this help message\n");
	ft_printf("EXAMPLES:\n");
	ft_printf("  fractol mandelbrot\n");
	ft_printf("  fractol julia -0.7 0.27015\n");
	ft_printf("CONTROLS:\n");
	ft_printf("  Mouse wheel   Zoom in/out\n");
	ft_printf("  ESC           Quit\n");
	ft_printf("  Q             Change Fractal color");
	ft_printf("  +             Raise the number of iterations by 10");
	ft_printf("  -             Decress the number of iterations by 10");
}

int	check_args(t_env *env, int argc, char **argv)
{
	if (argc == 1)
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: No fractal type specified\n");
		return (0);
	}
	if (ft_strcmp(argv[1], "-h") == 0 || ft_strcmp(argv[1], "--help") == 0)
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		return (0);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1],
			"julia") != 0)
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Unknown fractal type\n");
		return (0);
	}
	return (1);
}

static int	check_args_julia(t_env *env, int argc, char **argv)
{
	if (argc != 4)
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Julia set requires exactly 2 \
paraeters (c_real c_imag)\n");
		return (0);
	}
	if (!ft_isfloat(argv[2]) || !ft_isfloat(argv[3]))
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Julia parameters must be \
valid floating-point numbers\n");
		return (0);
	}
	return (1);
}

int	args_handler(t_env *env, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		env->fract->type = MALDEBROT_SET;
		return (1);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (!check_args_julia(env, argc, argv))
			return (0);
		env->fract->type = JULIA_SET;
		env->fract->px = ft_atod(argv[2]);
		env->fract->py = ft_atod(argv[3]);
		return (1);
	}
	return (0);
}
