/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:59:48 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/01 19:26:51 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>

typedef struct s_img_buffer
{
	void			*img;
	char			*img_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img_buffer;

typedef struct s_window
{
	int				width;
	int				height;
	int				need_redraw;
	void			*mlx;
	void			*x_window;
	t_img_buffer	*img;
}					t_window;

typedef enum e_fract_type
{
	MALDEBROT_SET,
	JULIA_SET
}					t_fract_type;

typedef struct s_fract
{
	int				max_iter;
	int				width;
	int				height;
	double			pcx;
	double			pcy;
	double			px;
	double			py;
	int				**color;
	double			zoom;
	double			x_offset;
	double			y_offset;
	t_fract_type	type;
}					t_fract;

typedef struct s_env
{
	t_window		*window;
	t_fract			*fract;
}					t_env;

t_env				*ft_init_env(int argc, char **argv);
void				*ft_destroy_env(t_env *env);

t_window			*ft_init_window(int width, int height, char *window_name);
void				*ft_destroy_window(t_window *window);
int					ft_close_window(t_env *env);

int					ft_mouse_handler(int mousecode, int x, int y, t_env *env);
int					ft_key_handler(int keycode, t_env *env);

t_img_buffer		*ft_init_img_buffer(t_window *window);
void				*ft_destroy_img_buffer(t_window *window);

void				ft_set_fract_draw(t_window *window, t_fract *fract);

void				ft_draw_img_buffer(t_window *window);

int					**alloc_color(t_window *window);
void				ft_free_color(t_fract *fract);

t_fract				*ft_init_fract(t_window *window, t_fract_type type,
						double px, double py);
void				*ft_detroy_fract(t_fract *fract);
void				ft_calc_coordinate(t_fract *fract, t_window *window, int x,
						int y);
void				ft_calc_fract(t_fract *fract, t_window *window);
int					ft_mandelbrot_calc_fract_points(t_fract *fract, double x,
						double y);
int					ft_julia_calc_fract_points(t_fract *fract, double x,
						double y);

int					check_args(t_env *env, int argc, char **argv);
int					args_handler(t_env *env, int argc, char **argv);

void				*ft_print_error(char *msg);
#endif
