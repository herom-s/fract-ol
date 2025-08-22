/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:59:48 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/22 19:14:27 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stddef.h>
typedef struct s_img_buffer
{
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img_buffer;

typedef struct s_window
{
	int				width;
	int				height;
	int				need_redraw;
	void			*mlx;
	void			*x_window;
	t_img_buffer	*img;
}				t_window;

typedef enum
{
	MALDEBROT_SET,
	JULIA_SET
} e_fract_type;

typedef struct s_complex
{
	double	*x;
	double	*y;
}				t_complex;

typedef struct s_fract
{
	t_complex		*z;
	t_complex		*c;
	int				*x;
	int				*y;
	int				**color;
	double			zoom;
	double			x_offeset;
	double			y_offeset;
	e_fract_type	type;
}				t_fract;

t_window		*ft_init_window(int width, int height, char *window_name);
void			ft_destroy_window(t_window *window);

t_img_buffer	*ft_init_img_buffer(t_window *window);
void			ft_destroy_img_buffer(t_window *window);

void			ft_set_fract_draw(t_window *window, t_fract *fract);

void			ft_draw_img_buffer(t_window *window);


t_fract			*ft_init_fract(t_window *window);
void			ft_detroy_fract(t_fract *fract);
void			ft_set_fract_c(t_fract *fract, t_window *window);
void			ft_set_fract_z(t_fract *fract, t_window *window);


void			ft_calc_fract(t_fract *fract, t_window *window, int max_inter);
void			ft_calc_fract_points(t_fract *fract, int x, int y, int max_iter);

t_complex		*ft_init_complex(size_t size_x, size_t size_y);
void			ft_destroy_complex(t_complex *complex);


#endif
