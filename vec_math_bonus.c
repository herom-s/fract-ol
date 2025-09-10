/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:41:33 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 02:42:18 by hermarti         ###   ########.fr       */
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

t_vec3	ft_vec3_scale(t_vec3 v, float s)
{
	t_vec3	res;

	res.x = v.x * s;
	res.y = v.y * s;
	res.z = v.z * s;
	return (res);
}

float	ft_vec3_magnitude(t_vec3 v)
{
	return (sqrt((ft_vec3_dot(v, v))));
}

t_vec3	ft_vec3_normalize(t_vec3 v)
{
	t_vec3	res;
	float	mag;

	mag = ft_vec3_magnitude(v);
	res.x = 0.0f;
	res.y = 0.0f;
	res.z = 0.0f;
	if (mag == 0.0f)
		return (res);
	res.x = v.x / mag;
	res.y = v.y / mag;
	res.z = v.z / mag;
	return (res);
}

float	ft_vec3_dot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
