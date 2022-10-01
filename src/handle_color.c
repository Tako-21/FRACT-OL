/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:50:29 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/01 14:26:21 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	create_trgb(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
