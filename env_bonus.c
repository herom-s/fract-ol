/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:05:10 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/04 19:05:18 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"

t_env	*ft_init_env(int argc, char **argv)
{
	t_env		*env;

	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (NULL);
	check_args(env, argc, argv);
	env->window = ft_init_window(800, 600, "fractol");
	if (!env->window)
	{
		ft_destroy_env(env);
		ft_print_error("Error: Failed to allocate memory to the window");
	}
	env->fract = ft_init_fract(env->window, MALDEBROT_SET, 0, 0);
	if (!env->fract)
	{
		ft_destroy_env(env);
		ft_print_error("Error: Failed to allocate memory to the fract");
	}
	args_handler(env, argc, argv);
	return (env);
}

void	*ft_destroy_env(t_env *env)
{
	if (env->fract)
		ft_detroy_fract(env->fract);
	if (env->window)
		ft_destroy_window(env->window);
	free(env);
	env = NULL;
	return (NULL);
}
