/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:27:01 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/01 18:11:23 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

t_env	*ft_init_env(int argc, char **argv)
{
	t_env		*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	check_args(env, argc, argv);
	env->window = ft_init_window(800, 600, "fractol");
	env->fract = ft_init_fract(env->window, MALDEBROT_SET, 0, 0);
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
