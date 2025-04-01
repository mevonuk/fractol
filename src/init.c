/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <mevonuk@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:22:28 by mevonuk           #+#    #+#             */
/*   Updated: 2024/01/16 11:02:28 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// display error message for no argument
int	error_empty_input(void)
{
	ft_printf("\nPlease choose what type of fractal you would like to see:\n\n");
	ft_printf("1: Julia set\n");
	ft_printf("2: Mandrelbrot set\n");
	ft_printf("3: Burning ship\n");
	ft_printf("4: Tricorn set\n\n");
	ft_printf("\tTwo additional parameters (between -1 and 1) can be\n");
	ft_printf("\tentered in the case of the Julia Set\n\n");
	return (1);
}

// check input (two floats) for Julia set
int	check_input(char *str)
{
	int	i;
	int	decimal;

	i = 0;
	decimal = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '.')
			decimal++;
		if (ft_isdigit(str[i]) == 1 || str[i] == '.')
			i++;
		else
			return (1);
	}
	if (decimal != 1)
		return (1);
	return (0);
}

// display various error messages if the number of arguments or 
// the arguemtns themselves are incorrect
int	entry_handling(t_fractol *vars, int argn, char **argv)
{
	vars->set = ft_atoi(argv[1]);
	vars->cx = -0.835;
	vars->cy = -0.2321;
	if (vars->set == 1)
	{
		if (argn == 4)
		{
			if (check_input(argv[2]) == 0 && check_input(argv[3]) == 0)
			{
				vars->cx = ft_atof(argv[2]);
				vars->cy = ft_atof(argv[3]);
			}
			else
				ft_printf("Invalid entry, using default values!\n");
		}
		else
			ft_printf("Improper number of arguments, using default values!\n");
	}
	if (vars->set < 1 || vars->set > 4)
	{
		ft_printf("Chosen set is not in expected range!\n");
		return (1);
	}
	set_boundaries(vars);
	return (0);
}

// set default boundaries for first display of fractol
void	set_boundaries(t_fractol *vars)
{
	vars->min_x = -2.0;
	vars->max_x = 2.0;
	vars->c0 = 120;
	vars->color_opt = 1;
	if (vars->set == 2)
		vars->max_x = 1.0;
	if (vars->set == 4)
		vars->max_x = 1.5;
	vars->min_y = -(vars->max_x - vars->min_x) * 0.5;
	if (vars->set == 3)
	{
		vars->min_x = -1.826;
		vars->max_x = -1.549;
		vars->min_y = -0.1483;
	}
	vars->max_y = vars->min_y + (vars->max_x - vars->min_x);
	vars->delta = (vars->max_x - vars->min_x) / (double)WIDTH;
}
