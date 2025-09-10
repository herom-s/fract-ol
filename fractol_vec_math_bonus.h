/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_vec_math_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:36:58 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 02:23:37 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_VEC_MATH_BONUS_H
# define FRACTOL_VEC_MATH_BONUS_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}			t_vec3;

t_vec3		ft_vec3_add(t_vec3 a, t_vec3 b);
t_vec3		ft_vec3_scale(t_vec3 v, float s);
float		ft_vec3_magnitude(t_vec3 v);
t_vec3		ft_vec3_normalize(t_vec3 v);
float		ft_vec3_dot(t_vec3 a, t_vec3 b);

#endif
