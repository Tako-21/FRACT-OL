/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:39:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 21:13:03 by mmeguedm         ###   ########.fr       */
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
# define KEY_PLUS 65451
# define KEY_MINUS 65453

/* Window dimension values  */
# define WIDTH 900 // Largeur de la fentre
# define HEIGHT 900 // Hauteur de la fenetre

/*	Code for fractal set  */
# define MANDELBROT	0
# define MULTIBROT	1
# define JULIA		2

/*	Definition of the boolean type  */
typedef enum s_bool
{
	FALSE = 3,
	TRUE
}	t_bool;

/* Definition of the image data structure  */
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_complex {
	double		max_r;
	double		min_r;
	double		max_i;
	double		min_i;
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	double	power;
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
	char		proc;
	t_img		img;
	t_complex	complex;
	t_mouse		mouse_pos;
}				t_data;

/* Function pointer required to correspond set and function.  */
typedef	int(*t_fp_fractal_set)();

/*	Array of correspondence between fractal set and args.  */
typedef struct	s_op_set
{
	char				*fractal_set;
	t_fp_fractal_set	fractal_fp;
}						t_op_set;


#endif
