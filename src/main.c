/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:41:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/22 18:56:06 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "tools.h"

#include "exit_error.h"
#include <stdio.h>
#include </usr/include/X11/X.h>
#include <stdlib.h>
#include "set.h"
#include "window_management.h"
#include "hook.h"
#include "shifting.h"
#include "utils.h"
#include "init.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data, argv, argc);
	mlx_loop(data.mlx);
}
