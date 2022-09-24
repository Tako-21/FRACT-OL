/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:18:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/24 20:56:55 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_error.h"
#include "utils.h"
#include <unistd.h>

void	exit_error(int sig_err)
{
	const char	*map_error[ERR__LENGHT] = {
		"Input error. Let's see together how to proceed\n",
		"Too few arguments. Let's see together how to proceed\n",
		"Too many arguments. Let's see together how to proceed\n"
	};

	ft_putstr_fd((char *)map_error[sig_err], STDERR_FILENO);
	exit(EXIT_FAILURE);
}
