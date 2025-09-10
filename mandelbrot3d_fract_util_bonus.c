/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3d_fract_util_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:07:54 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 02:40:39 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "fractol_vec_math_bonus.h"
#include <math.h>

typedef struct s_mandelbrot3d_vars
{
	t_vec3	z;
	float	iter;
	float	dr;
	float	r;
	float	power;
	float	theta;
	float	phi;
	float	zr;
}			t_mandelbrot3d_vars;

static void	ft_calculate_spherical(t_vec3 z, float r, float *theta,
		float *phi)
{
	*theta = acosf(z.z / r);
	*phi = atan2f(z.y, z.x);
}

static void	ft_apply_power_transform(t_vec3 *z, float zr, float theta,
		float phi)
{
	z->x = zr * sinf(theta) * cosf(phi);
	z->y = zr * sinf(theta) * sinf(phi);
	z->z = zr * cosf(theta);
}

static void	ft_init_mandelbrot3d_vars(t_fract *fract, t_mandelbrot3d_vars *vars,
		t_vec3 p)
{
	vars->z = p;
	vars->iter = 0.0f;
	vars->dr = 1.0f;
	vars->power = fract->power;
}

float	ft_mandelbrot3d_calc_dist(t_fract *fract, t_vec3 p)
{
	t_mandelbrot3d_vars	vars;
	float				dist;

	ft_init_mandelbrot3d_vars(fract, &vars, p);
	while (vars.iter < fract->max_iter)
	{
		vars.r = ft_vec3_magnitude(vars.z);
		if (vars.r > 4.0f)
			break ;
		ft_calculate_spherical(vars.z, vars.r, &vars.theta, &vars.phi);
		vars.dr = powf(vars.r, vars.power - 1.0f) * vars.power * vars.dr + 1.0f;
		vars.iter++;
		if (vars.iter >= fract->max_iter)
			return (0.0f);
		vars.zr = powf(vars.r, vars.power);
		vars.theta = vars.theta * vars.power;
		vars.phi = vars.phi * vars.power;
		ft_apply_power_transform(&vars.z, vars.zr, vars.theta, vars.phi);
		vars.z = ft_vec3_add(vars.z, p);
	}
	dist = (0.5f * logf(vars.r) * vars.r / vars.dr) * 0.9f;
	return (dist);
}
