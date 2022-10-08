/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:39:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/08 20:57:53 by mmeguedm         ###   ########.fr       */
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
# define WIDTH 900 // Largeur de la fentre
# define HEIGHT 900 // Hauteur de la fenetre


/*	To prevent integer overflow in expression of type ‘int’  */
# define INT_OVERFLOW 2147483648

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

/*	Required to initialize complex plane.  */
typedef struct s_complex {
	double			max_r;
	double			min_r;
	double			max_i;
	double			min_i;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			power;
	__uint16_t		max_iteration;
}	t_complex;

/*	Required for the dynamic Julia set to remember the last
	position of the mouse  */
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

/*	Array of correspondence between keycode and color scheme
	corresponding  */
typedef struct s_op_color_scheme
{
	int					keycode;
	t_fp_color_scheme	fp_color_scheme;
}						t_op_color_scheme;

/* Definition of the mlx_instance structure and the data structure  */
typedef struct s_data {
	void				*mlx;
	void				*win;
	char				*program_name;
	int					keycode_mouse;
	int					keycode_esc;
	int					keycode_keyboard;
	unsigned int		color;
	unsigned char		bool_space;
	t_fp_fractal_set	exe_fractal;
	t_fp_init_hook		exe_hook;
	t_fp_color_scheme	exe_color_scheme;
	t_img				img;
	t_complex			complex;
	t_mouse				mouse_pos;
}						t_data;

#endif
