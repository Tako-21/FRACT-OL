/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:00:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/22 16:13:12 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "tools.h"

t_fp_init_hook		get_hook(t_data *data, char **argv);
t_fp_fractal_set	get_set(t_data *data, char **argv);

void				init_mlx(t_data *data);
void				init_complex_plane(t_data *data);
void				init(t_data *data, char **argv, int argc);
void				init_hook(t_data *data);

#endif