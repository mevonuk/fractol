/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:03:16 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/15 11:08:06 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// get color in rainbow based on angle
int	get_rainbow_rgb(double z, int c0)
{
	double	angle;
	double	start;
	double	diff;
	int		i;
	int		comp[3];

	angle = z / MAX_ITERATIONS * 360 + c0;
	i = 0;
	while (i < 3)
	{
		start = ((i + 1) * 120) % 360;
		diff = get_diff(angle, start);
		if (diff < 60)
			comp[i] = diff / 60 * 155;
		else if (diff <= 180)
			comp[i] = 155;
		else if (diff < 240)
			comp[i] = (240 - diff) / 60 * 155;
		else
			comp[i] = 0;
		i++;
	}
	return (create_trgb(1, comp[0], comp[1], comp[2]));
}
