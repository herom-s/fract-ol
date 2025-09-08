/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:05:37 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/05 16:12:17 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define MAX_COLORS 3

typedef struct s_img_buffer	t_img_buffer;
typedef struct s_window		t_window;

typedef struct s_fract		t_fract;

typedef enum e_fract_type	t_fract_type;
typedef struct s_fract		t_fract;

typedef struct s_env
{
	t_window				*window;
	t_fract					*fract;
}							t_env;

t_env						*ft_init_env(int argc, char **argv);
void						*ft_destroy_env(t_env *env);

typedef struct s_window
{
	double					mx;
	double					my;
	int						width;
	int						height;
	int						need_redraw;
	void					*mlx;
	void					*x_window;
	t_img_buffer			*img;
}							t_window;

t_window					*ft_init_window(int width, int height,
								char *window_name);
void						*ft_destroy_window(t_window *window);
int							ft_close_window(t_env *env);

int							ft_mouse_handler(int mousecode, int x, int y,
								t_env *env);
int							ft_mouse_move_handler(int x, int y, t_env *env);

int							ft_key_handler(int keycode, t_env *env);

typedef struct s_img_buffer
{
	void					*img;
	char					*img_addr;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
}							t_img_buffer;

t_img_buffer				*ft_init_img_buffer(t_window *window);
void						*ft_destroy_img_buffer(t_window *window);

void						ft_set_fract_draw(t_window *window, t_fract *fract);

void						ft_draw_img_buffer(t_window *window);

int							ft_get_color_basic(t_fract *fract, double iter);
int							ft_get_color_psychedelic(t_fract *fract,
								double iter);
int							ft_get_color_iter_shifft(t_fract *fract,
								double iter);

int							**ft_alloc_color(t_window *window);
void						ft_free_color(t_fract *fract);

void						ft_set_get_color(t_fract *fract);

typedef enum e_fract_type
{
	MALDEBROT_SET,
	JULIA_SET,
	BURNING_SHIP_SET
}							t_fract_type;

typedef int					(*t_ft_get_color)(t_fract *fract, double iter);

typedef struct s_fract
{
	int						color_id;
	double					color_shift;
	int						need_zoom;
	double					max_iter;
	int						width;
	int						height;
	double					pcx;
	double					pcy;
	double					px;
	double					py;
	int						**color;
	double					zoom;
	double					x_offset;
	double					y_offset;
	t_fract_type			type;
	t_ft_get_color			get_color[MAX_COLORS];
}							t_fract;

t_fract						*ft_init_fract(t_window *window, t_fract_type type,
								double px, double py);
void						*ft_detroy_fract(t_fract *fract);
void						ft_calc_coordinate(t_fract *fract, t_window *window,
								int x, int y);
void						ft_calc_fract(t_fract *fract, t_window *window);
int							ft_mandelbrot_calc_fract_points(t_fract *fract,
								double x, double y);
int							ft_julia_calc_fract_points(t_fract *fract, double x,
								double y);
int							ft_burning_ship_calc_fract_points(t_fract *fract,
								double x, double y);

int							ft_check_args(t_env *env, int argc, char **argv);
int							ft_args_handler(t_env *env, int argc, char **argv);

void						*ft_print_error(char *msg);
#endif
