/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:39:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/09 22:53:30 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define RED    0xFF0000
# define GREEN  0x00FF00
# define BLUE   0x0000FF

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_color {
	int	red;
	int	green;
	int	blue;
	int	purple;
	int	orange;
	int	actual_color;
}		t_color;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_img	img;
}			t_data;

#endif