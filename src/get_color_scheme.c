/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_scheme.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:44:16 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/05 12:24:53 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static t_op_color_scheme	*color_scheme_storage(void)
{
	static t_op_color_scheme	color_scheme_storage [] = {
	{KEY_ONE, set_color_one},
	{KEY_TWO, set_color_two},
	{KEY_THREE, set_color_three},
	{0, NULL},
	};

	return (color_scheme_storage);
}

void	get_color_scheme(t_data *data)
{
	static t_op_color_scheme	*color_scheme;

	color_scheme = color_scheme_storage();
	while (color_scheme->fp_color_scheme)
	{
		if (data->keycode_keyboard == color_scheme->keycode)
			data->exe_color_scheme = color_scheme->fp_color_scheme;
		color_scheme++;
	}
}
