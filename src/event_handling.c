/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <mevonuk@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:04:06 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/12 16:31:03 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// shift the center of the graphic up, down, left, or right
void	shift(int button, t_fractol *vars)
{
	if (button == MOUSE_BTN_R || button == KEY_RIGHT)
		vars->min_x = vars->min_x - vars->delta * 0.01 * WIDTH;
	else if (button == MOUSE_BTN_L || button == KEY_LEFT)
		vars->min_x = vars->min_x + vars->delta * 0.01 * WIDTH;
	else if (button == KEY_UP)
	{
		if (vars->set != 3)
			vars->min_y = vars->min_y - vars->delta * 0.01 * HEIGHT;
		else
			vars->min_y = vars->min_y + vars->delta * 0.01 * HEIGHT;
	}
	else if (button == KEY_DOWN)
	{
		if (vars->set != 3)
			vars->min_y = vars->min_y + vars->delta * 0.01 * HEIGHT;
		else
			vars->min_y = vars->min_y - vars->delta * 0.01 * HEIGHT;
	}
	vars->max_x = vars->min_x + vars->delta * WIDTH;
	vars->max_y = vars->min_y + vars->delta * HEIGHT;
}

// zoom in or out on the view
void	zoom(int button, int x, int y, t_fractol *vars)
{
	double	zx;
	double	zy;

	zx = vars->min_x + x * vars->delta;
	if (vars->set != 3)
		zy = vars->max_y - y * vars->delta;
	else
		zy = vars->min_y + y * vars->delta;
	if (button == MOUSE_WHEEL_DOWN || button == KEY_PLUS)
		vars->delta = 0.5 * vars->delta;
	if (button == MOUSE_WHEEL_UP || button == KEY_MINUS)
		vars->delta = 2.0 * vars->delta;
	vars->min_x = zx - vars->delta * 0.5 * WIDTH;
	vars->max_x = vars->min_x + vars->delta * WIDTH;
	vars->min_y = zy - vars->delta * 0.5 * HEIGHT;
	vars->max_y = vars->min_y + vars->delta * HEIGHT;
}

// take in the key value and call the shift, zoom, or reset appropriately
int	key_hook(int keycode, t_fractol *vars)
{
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		shift(keycode, vars);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		shift(keycode, vars);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		zoom(keycode, WIDTH / 2, HEIGHT / 2, vars);
	else if (keycode == KEY_HOME || keycode == KEY_ZERO)
		set_boundaries(vars);
	else if (keycode == KEY_COLOR_LEFT || keycode == KEY_COLOR_RIGHT)
		shift_color(keycode, vars);
	else if (keycode == KEY_COLOR)
	{
		if (vars->color_opt == 1)
			vars->color_opt = 0;
		else
			vars->color_opt = 1;
	}
	return (0);
}

// take in the mouse value and call the shift, zoom or reset appropriately
int	mouse_event(int button, int x, int y, t_fractol *vars)
{
	if (button == MOUSE_BTN_L || button == MOUSE_BTN_R)
		shift(button, vars);
	else if (button == MOUSE_WHEEL_BTN)
		set_boundaries(vars);
	else if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
		zoom(button, x, y, vars);
	return (0);
}
