/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler_help_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:38:55 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/09 23:42:41 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_types(void)
{
	ft_printf("FRACTAL TYPES:\n");
	ft_printf("  mandelbrot    Generate Mandelbrot set\n");
	ft_printf("  julia         Generate Julia set \
(requires c_real c_imag parameters)\n");
	ft_printf("  mandelbrot3d  Generate 3D Mandelbrot set \
(requires power parameter)\n");
	ft_printf("  julia3d       Generate 3D Julia set \
(requires c_x/c_real c_y/c_imag c_z parameters)\n");
}

static void	ft_print_options(void)
{
	ft_printf("OPTIONS:\n");
	ft_printf("  -h, --help    Show this help message\n");
}

static void	ft_print_examples(void)
{
	ft_printf("EXAMPLES:\n");
	ft_printf("  fractol mandelbrot\n");
	ft_printf("  fractol julia -0.7 0.27015\n");
	ft_printf("  fractol burning_ship\n");
	ft_printf("  fractol mandelbrot3d 2.0\n");
	ft_printf("  fractol julia3d -0.7 0.27015 0.0\n");
}

static void	ft_print_controls(void)
{
	ft_printf("CONTROLS:\n");
	ft_printf("  Mouse wheel   Zoom in/out\n");
	ft_printf("  ESC           Quit\n");
	ft_printf("  Q             Change Fractal color\n");
	ft_printf("  E             Raise Fractal color shift\n");
	ft_printf("  R             Decrease Fractal color shift\n");
	ft_printf("  1             Change Fractal to Mandelbrot\n");
	ft_printf("  2             Change Fractal to Julia\n");
	ft_printf("  3             Change Fractal to Burning Ship\n");
	ft_printf("  +             Raise the number of iterations by 10\n");
	ft_printf(" ↑|w            Move up in the fractal\n");
	ft_printf(" ↓|s            Move down in the fractal\n");
	ft_printf(" →|d            Move right in the fractal\n");
	ft_printf(" ←|a            Move left in the fractal\n");
	ft_printf("  u             Rotate up the 3D fractal\n");
	ft_printf("  d             Rotate down the 3D fractal\n");
	ft_printf("  h             Rotate left the 3D fractal\n");
	ft_printf("  k             Rotate right the 3D fractal\n");
}

void	ft_print_arg_help(void)
{
	ft_printf("Usage: fractol [FRACTAL_TYPE] [OPTIONS]\n\n");
	ft_print_types();
	ft_print_options();
	ft_print_examples();
	ft_print_controls();
}
