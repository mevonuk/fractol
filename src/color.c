/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:03:48 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/02 13:31:00 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// store RGB color in an integer
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// get difference between two angles on a 360 degree wheel
double	get_diff(double a, double b)
{
	if (a > b)
		return (a - b);
	else
		return (a + 360 - b);
}

// get color based on color scheme
int	get_color(double z, int c0, int color_opt)
{
	if (color_opt == 1)
		return (get_rainbow_rgb(z, c0));
	else
		return (stripes(z, c0));
}

// shift color
void	shift_color(int button, t_fractol *vars)
{
	if (button == KEY_COLOR_LEFT)
		vars->c0 = vars->c0 - 2;
	if (button == KEY_COLOR_RIGHT)
		vars->c0 = vars->c0 + 2;
	if (vars->c0 < 0)
		vars->c0 = vars->c0 + 360;
	if (vars->c0 > 360)
		vars->c0 = vars->c0 - 360;
}
