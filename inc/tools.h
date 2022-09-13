/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:39:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/13 18:13:41 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include <unistd.h>

/* Hexadecimal code for color use  */
# define RED    0xFF0000
# define GREEN  0x00FF00
# define BLUE   0x0000FF
# define BLACK   0x000000

/* Iteration of Z which will partly fix the quality of
   the final rendering  */
# define MAX_ITERATION 80

/* Window dimension values  */
# define WIDTH 270 // Largeur de la fentre
# define HEIGHT 240 // Hauteur de la fenetre

/* Definition of the boolean type  */
typedef enum e_bool
{
	TRUE,
	FALSE
}			t_bool;

/* Definition of the image data structure  */
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

/* Definition of the mlx_instance structure and the data structure  */
typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_img	img;
}			t_data;

#endif