/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:19:11 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/28 16:13:40 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_ERROR_H
# define EXIT_ERROR_H

# include <stdlib.h>
# include <stdio.h>

/* Definition of ERROR_SIGNAL  */
typedef enum e_sig_err {
	ERR_NAME,
	ERR_ARG_LOW,
	ERR_ARG_HIGH,
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

#endif
