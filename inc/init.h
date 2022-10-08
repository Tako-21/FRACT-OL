/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:00:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/08 20:32:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "tools.h"

t_fp_init_hook		get_hook(t_data *data, char **argv);
t_fp_fractal_set	get_set(char **argv);

void				init_mlx(t_data *data);
void				init_complex_plane(t_data *data);
void				init(t_data *data, char **argv, int argc);
void				init_hook(t_data *data);
void				init_julia(t_data *data, char **argv, int argc);

void				print_controls(void);
void				print_help(void);

#endif
