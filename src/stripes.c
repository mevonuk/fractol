/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:54:09 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/15 11:52:58 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	stripes(double z, int c0)
{
	double	angle;
	int		i;
	int		comp[3];

	angle = z / MAX_ITERATIONS * 256 + c0;
	i = 0;
	while (i < 3)
	{
		comp[i] = (int)angle % 40 * 250;
		i++;
	}
	return (create_trgb(1, comp[0], comp[1], comp[2]));
}
