/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:51:01 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/15 09:51:22 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// put pixel with color depending on fractol value
void	img_pix_put(t_fractol *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

// fill the image file with the colored pixels based on the chosen fractol
void	fill_image(t_fractol vars)
{
	int		i;
	int		j;
	int		color;

	i = -1;
	while (i++ < WIDTH)
	{
		j = -1;
		while (j++ < HEIGHT)
		{
			if (vars.set == 1)
				color = julia_set(vars, i, j);
			else if (vars.set == 2)
				color = mandelbrot_set(vars, i, j);
			else if (vars.set == 3)
				color = burning_ship(vars, i, j);
			else if (vars.set == 4)
				color = tricorn_set(vars, i, j);
			img_pix_put(&vars, i, j, color);
		}
	}
}

// render the image into the window
int	render(t_fractol *vars)
{
	fill_image(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

// destroy window and display and free data with closing window with mouse
int	on_destroy(t_fractol *data)
{
	if (!data)
		exit(0);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

// close window and free memory with ESC key
int	close_win(int keycode, t_fractol *vars)
{
	if (keycode == ESC)
		on_destroy(vars);
	return (0);
}
