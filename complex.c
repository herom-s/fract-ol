/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:09:13 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/22 19:19:29 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

t_complex	*ft_init_complex(size_t size_x, size_t size_y)
{
	t_complex	*complex;

	complex = malloc(sizeof(t_complex));
	if (!complex)
		return (NULL);
	complex->x = malloc(size_x * sizeof(double));
	if (!complex->x)
	{
		free(complex);
		complex = NULL;
		return (NULL);
	}
	complex->y = malloc(size_y * sizeof(double));
	if (!complex->y)
	{
		free(complex->x);
		complex->x = NULL;
		free(complex);
		complex = NULL;
		return (NULL);
	}
	return (complex);
}

void	ft_destroy_complex(t_complex *complex)
{
	free(complex->x);
	complex->x = NULL;
	free(complex->y);
	complex->y = NULL;
	free(complex);
	complex = NULL;
}
