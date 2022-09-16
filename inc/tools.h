/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:39:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 16:17:07 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>

/* Hexadecimal code for color use  */
# define RED    0xFF0000
# define GREEN  0x00FF00
# define BLUE   0x0000FF
# define BLACK   0x000000
# define ORANGE 0xff8000

/* Mouse code for mlx_instance  */
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* Key code for mlx_instance  */
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_PG_UP 65365
# define KEY_PG_DOWN 65366

# define TMP_SCROLL_UP 105
# define TMP_SCROLL_DOWN 111
# define TMP_SCROLL 21

/* Window dimension values  */
# define WIDTH 900 // Largeur de la fentre
# define HEIGHT 900 // Hauteur de la fenetre

/* Definition of the boolean type  */
typedef enum e_move
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}			t_move;

/* Definition of the image data structure  */
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_complex {
	double		x;
	double		y;
	double		max_r;
	double		min_r;
	double		max_i;
	double		min_i;
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	__uint16_t	max_iteration;
}	t_complex;


typedef struct s_mouse {
	int	x;
	int	y;
}	t_mouse;

/* Definition of the mlx_instance structure and the data structure  */
typedef struct s_data {
	void		*mlx;
	void		*win;
	t_img		img;
	t_complex	complex;
	t_mouse		mouse_pos;
}				t_data;

#endif
