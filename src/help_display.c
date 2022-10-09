/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:55:48 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/09 19:39:41 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"

void	print_help(void)
{
	ft_putstr_fd("\033[1;36m*-----------------------------------------*\n", 1);
	ft_putstr_fd("|                 \033[1;96mFRACT'OL\033[1;36m", 1);
	ft_putstr_fd("                |\n", 1);
	ft_putstr_fd("*-----------------------------------------*\033[0m\n", 1);
	ft_putstr_fd("How it works ?\n", 1);
	ft_putstr_fd("You can choose between three fractals :\n", 1);
	ft_putstr_fd("\t\033[0;36mMandelbrot\n\tJulia\n\tMultibrot\033[0m\n", 1);
	ft_putstr_fd("Usage example : \033[0;32m./fractol\033[0m <name>\n\n", 1);
	ft_putstr_fd("For Julia it's possible to create different set by\n", 1);
	ft_putstr_fd("giving numeric parameters to the program.\n", 1);
	ft_putstr_fd("Usage example : \033[0;32m./fractol ", 1);
	ft_putstr_fd("\033[0mJulia -0.7269 0.1889\n\n", 1);
	ft_putstr_fd("If no parameter is given to Julia, ", 1);
	ft_putstr_fd("the program will run with\n", 1);
	ft_putstr_fd("predefines parameters.\n", 1);
	ft_putstr_fd("Here is a non-exhaustive list of parameters for Julia :\n", 1);
	ft_putstr_fd("\t\033[0;36m-0.4    0.6\n", 1);
	ft_putstr_fd("\t 0.285  0\n", 1);
	ft_putstr_fd("\t 0.285  0.01\n", 1);
	ft_putstr_fd("\t 0.45   0.1428\n", 1);
	ft_putstr_fd("\t-0.835 -0.2321\n\n", 1);
}

void	print_controls(void)
{
	ft_putstr_fd("\033[1;36m*-----------------------------------------*\n", 1);
	ft_putstr_fd("|                 \033[1;96mCONTROLS\033[1;36m", 1);
	ft_putstr_fd("                |\n", 1);
	ft_putstr_fd("*-----------------------------------------*\033[0m\n", 1);
	ft_putstr_fd("To navigate into the fractal.\n", 1);
	ft_putstr_fd("\033[0;36mright arrow.\t\t\033[0mmove right.\n", 1);
	ft_putstr_fd("\033[0;36mleft arrow.\t\t\033[0mmove left.\n", 1);
	ft_putstr_fd("\033[0;36mup arrow.\t\t\033[0mmove up.\n", 1);
	ft_putstr_fd("\033[0;36mdown arrow.\t\t\033[0mmove down.\n\n", 1);
	ft_putstr_fd("To zoom in or zoom out.\n", 1);
	ft_putstr_fd("\033[0;36mscroll in.\t\t\033[0mzoom in.\n", 1);
	ft_putstr_fd("\033[0;36mscroll out.\t\t\033[0mzoom out.\n\n", 1);
	ft_putstr_fd("\033[0mTo increase or decrease the precision.\n", 1);
	ft_putstr_fd("\033[0;36mpage up. \t\t\033[0mincrease precision.\n", 1);
	ft_putstr_fd("\033[0;36mpage down.\t\t\033[0mdecrease precision.\n\n", 1);
	ft_putstr_fd("To change the color scheme.\n", 1);
	ft_putstr_fd("\033[0;36m1.\t\t\t\033[0mapply the first color scheme.\n", 1);
	ft_putstr_fd("\033[0;36m2.\t\t\t\033[0mapply the second color scheme.\n", 1);
	ft_putstr_fd("\033[0;36m3.\t\t\t\033[0mapply the thirst color scheme.\n\n", 1);
	ft_putstr_fd("Only for Julia.\n", 1);
	ft_putstr_fd("\033[0;36mleft click.\t\t\033[0mmodify the Julia set.\n\n", 1);
	ft_putstr_fd("Only for Multibrot.\n", 1);
	ft_putstr_fd("\033[0;36mspace.\t\t\t\033[0menable/disable animation.\n", 1);
	ft_putstr_fd("\n\n\033[0;33mHave fun :)\033[0m\n\n", 1);
}
