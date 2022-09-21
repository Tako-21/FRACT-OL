/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:41:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/21 19:06:04 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "tools.h"
#include "zoom_mouse_hook.h"
#include "exit_error.h"
#include <stdio.h>
#include </usr/include/X11/X.h>
#include <stdlib.h>
#include "set.h"
#include "window_management.h"
#include "hook_management.h"
#include "shifting.h"
#include "utils.h"
#include "init.h"




int	main(int argc, char **argv)
{
	t_data	data;
	init(&data, argv, argc);
	// multibrot_set(&data, 0);
	mlx_loop(data.mlx);
}
