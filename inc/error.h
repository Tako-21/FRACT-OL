/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:19:11 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/09 19:15:31 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdlib.h>
# include <stdio.h>
# include "tools.h"

/* Definition of ERROR_SIGNAL  */
typedef enum e_sig_err {
	ERR_NAME,
	ERR_ARG_LOW,
	ERR_ARG_HIGH,
	ERR_MLX,
	ERR_INT_OVERFLOW,
	ERR__LENGHT
}	t_sig_err;

/* It required by exit_error in <main.c> to handle differents
   types of errors  */
typedef struct s_error
{
	int		sig_err;
	char	*sig_msg;
}			t_error;

void	exit_error(int sig_err);
void	parse_args(t_data *data, int argc, char **argv);
t_bool	allowed_string(char *str);

#endif
