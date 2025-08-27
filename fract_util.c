/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:54:49 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/26 18:07:29 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	**alloc_color(t_window *window)
{
	int	i;
	int	**color;

	i = 0;
	color = malloc(window->width * sizeof(int *));
	if (!color)
		return (NULL);
	while (i < window->width)
	{
		color[i] = malloc(window->height * sizeof(int));
		if (!color[i])
		{
			while (i > 0)
			{
				free(color[i]);
				i--;
			}
			free(color);
			return (NULL);
		}
		i++;
	}
	return (color);
}

void	ft_free_color(t_fract *fract)
{
	int	i;

	i = 0;
	if (!fract->color)
		return ;
	while (i < fract->width)
	{
		free(fract->color[i]);
		i++;
	}
	free(fract->color);
}