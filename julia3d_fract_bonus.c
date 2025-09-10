/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d_fract_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:39:49 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/10 02:46:49 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "fractol_vec_math_bonus.h"
#include <math.h>

typedef struct s_camera
{
	float		rotation_x;
	float		rotation_y;
	float		distance;
}				t_camera;

typedef struct s_ray_data
{
	t_vec3		origin;
	t_vec3		direction;
	float		total_distance;
	int			steps;
}				t_ray_data;

static t_vec3	ft_rotate_point(t_vec3 p, float rx, float ry)
{
	t_vec3	result;
	float	temp_y;
	float	temp_z;

	temp_y = p.y * cosf(rx) - p.z * sinf(rx);
	temp_z = p.y * sinf(rx) + p.z * cosf(rx);
	p.y = temp_y;
	p.z = temp_z;
	result.x = p.x * cosf(ry) + p.z * sinf(ry);
	result.y = p.y;
	result.z = -p.x * sinf(ry) + p.z * cosf(ry);
	return (result);
}

static void	ft_init_ray_data(t_fract *fract, float x, float y,
		t_ray_data *ray)
{
	ray->origin.x = 0.0f;
	ray->origin.y = 0.0f;
	ray->origin.z = -4.0f / fract->zoom;
	ray->direction.x = x;
	ray->direction.y = y;
	ray->direction.z = 1.0f;
	ray->direction = ft_vec3_normalize(ray->direction);
	ray->total_distance = 0.1f;
	ray->steps = 0;
}

static int	ft_calculate_shading(t_fract *fract, int steps, int max_steps)
{
	float	iter;

	iter = (float)fract->max_iter - ((float)steps / max_steps)
		* fract->max_iter;
	return (fract->get_color[fract->color_id](fract, iter));
}

static int	ft_ray_march(t_fract *fract, t_ray_data *ray)
{
	t_vec3	current_pos;
	t_vec3	fractal_pos;
	float	distance_to_surface;
	int		max_steps;

	max_steps = fract->max_iter;
	while (ray->steps < max_steps && ray->total_distance < 20.0f)
	{
		current_pos = ft_vec3_add(ray->origin, ft_vec3_scale(ray->direction,
					ray->total_distance));
		fractal_pos.x = current_pos.x + fract->x_offset;
		fractal_pos.y = current_pos.y + fract->y_offset;
		fractal_pos.z = current_pos.z + fract->z_offset;
		fractal_pos = ft_rotate_point(fractal_pos, fract->x_rotation,
				fract->y_rotation);
		distance_to_surface = ft_julia3d_calc_dist(fract, fractal_pos);
		if (distance_to_surface < 0.001f)
			return (ft_calculate_shading(fract, ray->steps, max_steps));
		ray->total_distance += distance_to_surface * 0.9f;
		ray->steps++;
	}
	return (0);
}

int	ft_julia3d_calc_fract_points(t_fract *fract, float x, float y)
{
	t_ray_data	ray;

	ft_init_ray_data(fract, x, y, &ray);
	return (ft_ray_march(fract, &ray));
}
