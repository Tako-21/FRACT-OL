/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:39:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/01 19:21:26 by mmeguedm         ###   ########.fr       */
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
# define LEFT_CLICK 1
# define RIGHT_CLICK 2

/* Key code for mlx_instance  */
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_PG_UP 65365
# define KEY_PG_DOWN 65366
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_SPACE 32
# define KEY_ESC 65307
# define KEY_ONE 65436
# define KEY_TWO 65433
# define KEY_THREE 65435

/* Window dimension values  */
# define WIDTH 600 // Largeur de la fentre
# define HEIGHT 600 // Hauteur de la fenetre

/*	Code for fractal set  */
# define MANDELBROT	0
# define MULTIBROT	1
# define JULIA		2

/*	Definition of the boolean type  */
typedef enum e_bool
{
	FALSE,
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
	long double		max_r;
	long double		min_r;
	long double		max_i;
	long double		min_i;
	long double		z_r;
	long double		z_i;
	long double		c_r;
	long double		c_i;
	long double		power;
	__uint16_t		max_iteration;
}	t_complex;

typedef struct s_mouse {
	int	last_x;
	int	last_y;
}	t_mouse;

/*	Function pointer pointing to the set choosen by the user.  */
typedef int(*t_fp_fractal_set)();

/*	Function pointer pointing to the key/mouse_hook corresponding
	to the set  */
typedef int(*t_fp_init_hook)();

/*	Function pointer to the corresponding color scheme  */
typedef int(*t_fp_color_scheme)();

/*	Array of correspondence between fractal set and args.  */
typedef struct s_op_set
{
	char				*fractal_set;
	t_fp_fractal_set	fp_op;
}						t_op_set;

/* Definition of the mlx_instance structure and the data structure  */
typedef struct s_data {
	void				*mlx;
	void				*win;
	char				*program_name;
	char				release;
	int					keycode_mouse;
	int					keycode_esc;
	int					keycode_keyboard;
	unsigned char		bool_space;
	t_fp_fractal_set	exe_fractal;
	t_fp_init_hook		exe_hook;
	t_fp_color_scheme	exe_color_scheme;
	t_img				img;
	t_complex			complex;
	t_mouse				mouse_pos;
}						t_data;

#endif
