/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:18:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/09 19:41:30 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "error.h"
#include "utils.h"
#include <unistd.h>

void	exit_error(int sig_err)
{
	const char	*map_error[ERR__LENGHT] = {
		"Input error.\n\n",
		"Too few arguments.\n\n",
		"Too many arguments.\n\n",
		"It seems that there is a problem with the mlx...\n\n",
		"Type overflow allowed.\n\n",
	};

	ft_putstr_fd("\033[0;31mINFO\033[0m : ", STDERR_FILENO);
	ft_putstr_fd((char *)map_error[sig_err], STDERR_FILENO);
	ft_putstr_fd("Let's see together how to proceed.\n", STDERR_FILENO);
	print_help();
	print_controls();
	exit(EXIT_FAILURE);
}
