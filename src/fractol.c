/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <mevonuk@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:00:21 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/15 11:55:15 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_commands(void)
{
	ft_printf("*************************************************************\n");
	ft_printf("To zoom in : press the + key or use roll the mouse wheel down\n");
	ft_printf("To zoom out: press the - key or use roll the mouse wheel up\n\n");
	ft_printf("Shift the center view right: right arrow or right mouse click\n");
	ft_printf("Shift the center view left : left  arrow or left  mouse click\n");
	ft_printf("\nTo shift the color scale: use the < and > keys\n\n");
	ft_printf("To toggle between color and greyscale: press the c key\n\n");
	ft_printf("To reset to the default veiw and color:\n");
	ft_printf("  Press the Home key, the 0 key, or the middle mouse button\n");
	ft_printf("*************************************************************\n");
}

// initialize fractorl and monitor events
int	main(int argn, char **argv)
{
	t_fractol	vars;

	if (argn == 1)
		return (error_empty_input());
	if (entry_handling(&vars, argn, argv) == 1)
		return (1);
	print_commands();
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	if (vars.win == NULL)
		return (free(vars.mlx), 1);
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp,
			&vars.line_len, &vars.endian);
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, &mouse_event, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
