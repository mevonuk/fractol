/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:11:55 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/12 16:21:16 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// julia set
int	julia_set(t_fractol vars, int x, int y)
{
	double	zx;
	double	zy;
	double	xtemp;
	int		i;
	int		color;

	zx = vars.min_x + x * vars.delta;
	zy = vars.max_y - y * vars.delta;
	i = 0;
	while (zx * zx + zy * zy < 4.0 && i < MAX_ITERATIONS)
	{
		xtemp = zx * zx - zy * zy + vars.cx;
		zy = 2 * zx * zy + vars.cy;
		zx = xtemp;
		i++;
	}
	if (i == MAX_ITERATIONS)
		color = get_color(zx * zx + zy * zy, vars.c0, vars.color_opt);
	else
		color = get_color(i, vars.c0, vars.color_opt);
	return (color);
}

// mandelbrot is js julia set but with cx = zx and cy = zy
int	mandelbrot_set(t_fractol vars, int x, int y)
{
	double	zx;
	double	zy;
	double	xtemp;
	int		i;
	int		color;

	zx = vars.min_x + x * vars.delta;
	zy = vars.max_y - y * vars.delta;
	vars.cx = zx;
	vars.cy = zy;
	i = 0;
	while (zx * zx + zy * zy < 4.0 && i < MAX_ITERATIONS)
	{
		xtemp = zx * zx - zy * zy + vars.cx;
		zy = 2 * zx * zy + vars.cy;
		zx = xtemp;
		i++;
	}
	if (i == MAX_ITERATIONS)
		color = get_color(zx * zx + zy * zy, vars.c0, vars.color_opt);
	else
		color = get_color(i, vars.c0, vars.color_opt);
	return (color);
}
