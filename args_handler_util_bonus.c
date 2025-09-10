/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler_util_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:13:37 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 00:14:25 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"

int	ft_check_args(t_env *env, int argc, char **argv)
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
		exit(EXIT_SUCCESS);
		return (0);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1],
			"julia") != 0 && ft_strcmp(argv[1], "burning_ship")
		&& ft_strcmp(argv[1], "mandelbrot3d") != 0 && ft_strcmp(argv[1],
			"julia3d") != 0)
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Unknown fractal type\n");
		return (0);
	}
	return (1);
}

int	ft_check_args_julia(t_env *env, int argc, char **argv)
{
	if (argc != 4)
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Julia set requires exactly 2 \
parameters (c_real c_imag)\n");
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

int	ft_check_args_julia3d(t_env *env, int argc, char **argv)
{
	if (argc != 5)
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Julia3D set requires exactly 3 \
parameters (c_x c_y c_z)\n");
		return (0);
	}
	if (!ft_isfloat(argv[2]) || !ft_isfloat(argv[3]) || !ft_isfloat(argv[4]))
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Julia3D parameters must be \
valid floating-point numbers\n");
		return (0);
	}
	return (1);
}

int	ft_check_args_mandelbrot3d(t_env *env, int argc, char **argv)
{
	if (argc != 3)
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Mandelbrot3D set requires exactly 1 \
parameter (power)\n");
		return (0);
	}
	if (!ft_isnumber(argv[2]))
	{
		ft_destroy_env(env);
		ft_print_arg_help();
		ft_print_error("Error: Mandelbrot3D parameters must be \
a valid number\n");
		return (0);
	}
	return (1);
}
