/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <mevonuk@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:10:34 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/12 16:22:57 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60

typedef struct s_fractol {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			endian;
	int			line_len;
	int			set;
	int			c0;
	double		cy;
	double		cx;
	int			color_opt;
	double		min_x;
	double		min_y;
	double		max_x;
	double		max_y;
	double		delta;
}				t_fractol;

int		get_rainbow_rgb(double z, int c0);
int		stripes(double z, int c0);
void	shift_color(int button, t_fractol *vars);
double	get_diff(double a, double b);
int		get_color(double z, int c0, int color_opt);
int		create_trgb(int t, int r, int g, int b);

int		julia_set(t_fractol vars, int x, int y);
int		mandelbrot_set(t_fractol vars, int x, int y);
int		burning_ship(t_fractol vars, int x, int y);
int		tricorn_set(t_fractol vars, int x, int y);

int		key_hook(int keycode, t_fractol *vars);
int		mouse_event(int button, int x, int y, t_fractol *vars);
int		close_win(int keycode, t_fractol *vars);
int		render(t_fractol *vars);
void	fill_image(t_fractol vars);
int		on_destroy(t_fractol *data);

int		error_empty_input(void);
int		entry_handling(t_fractol *vars, int argn, char **argv);
void	set_boundaries(t_fractol *vars);

#endif
