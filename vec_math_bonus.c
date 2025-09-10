/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_math_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:41:33 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/09 16:03:19 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_vec_math_bonus.h"
#include <math.h>

t_vec3	ft_vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vec3	ft_vec3_scale(t_vec3 v, double s)
{
	t_vec3	res;

	res.x = v.x * s;
	res.y = v.y * s;
	res.z = v.z * s;
	return (res);
}

double	ft_vec3_magnitude(t_vec3 v)
{
	return (sqrt((ft_vec3_dot(v, v))));
}

t_vec3	ft_vec3_normalize(t_vec3 v)
{
	t_vec3	res;
	double	mag;

	mag = ft_vec3_magnitude(v);
	res.x = 0.0;
	res.y = 0.0;
	res.z = 0.0;
	if (mag == 0.0)
		return (res);
	res.x = v.x / mag;
	res.y = v.y / mag;
	res.z = v.z / mag;
	return (res);
}

double	ft_vec3_dot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
