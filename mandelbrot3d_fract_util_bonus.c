/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3d_fract_util_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:07:54 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/09 21:57:08 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "fractol_vec_math_bonus.h"
#include <math.h>

typedef struct s_mandelbrot3d_vars
{
	t_vec3	z;
	double	iter;
	double	dr;
	double	r;
	double	power;
	double	theta;
	double	phi;
	double	zr;
}			t_mandelbrot3d_vars;

static void	ft_calculate_spherical(t_vec3 z, double r, double *theta,
		double *phi)
{
	*theta = acos(z.z / r);
	*phi = atan2(z.y, z.x);
}

static void	ft_apply_power_transform(t_vec3 *z, double zr, double theta,
		double phi)
{
	z->x = zr * sin(theta) * cos(phi);
	z->y = zr * sin(theta) * sin(phi);
	z->z = zr * cos(theta);
}

static void	ft_init_mandelbrot3d_vars(t_fract *fract, t_mandelbrot3d_vars *vars,
		t_vec3 p)
{
	vars->z = p;
	vars->iter = 0.0;
	vars->dr = 1.0;
	vars->power = fract->power;
}

double	ft_mandelbrot3d_calc_dist(t_fract *fract, t_vec3 p)
{
	t_mandelbrot3d_vars	vars;
	double				dist;

	ft_init_mandelbrot3d_vars(fract, &vars, p);
	while (vars.iter < fract->max_iter)
	{
		vars.r = ft_vec3_magnitude(vars.z);
		if (vars.r > 4.0)
			break ;
		ft_calculate_spherical(vars.z, vars.r, &vars.theta, &vars.phi);
		vars.dr = pow(vars.r, vars.power - 1.0) * vars.power * vars.dr + 1.0;
		vars.iter++;
		if (vars.iter >= fract->max_iter)
			return (0.0);
		vars.zr = pow(vars.r, vars.power);
		vars.theta = vars.theta * vars.power;
		vars.phi = vars.phi * vars.power;
		ft_apply_power_transform(&vars.z, vars.zr, vars.theta, vars.phi);
		vars.z = ft_vec3_add(vars.z, p);
	}
	dist = (0.5 * log(vars.r) * vars.r / vars.dr) * 0.9;
	return (dist);
}
