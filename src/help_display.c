/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:55:48 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/05 20:51:01 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"



void	print_help(void)
{
	ft_putstr_fd("*-----------------------------------------*\n", 1);
	ft_putstr_fd("|                 \033[1;30mFRACT'OL\033[0m                |\n", 1);
	ft_putstr_fd("*-----------------------------------------*\n", 1);
	ft_putstr_fd("How it works ?\n", 1);
	ft_putstr_fd("You can choose between three fractals :\n", 1);
	ft_putstr_fd("\t\033[0;36mMandelbrot\n\tJulia\n\tMultibrot\033[0m\n", 1);
}
