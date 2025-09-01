/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:13:58 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/27 18:22:19 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_print_error(char *msg)
{
	ft_dprintf(2, "%s", msg);
	exit(EXIT_FAILURE);
	return (NULL);
}
