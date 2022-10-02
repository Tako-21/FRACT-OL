/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:41:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/02 21:10:00 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "tools.h"

t_bool			ft_strcmp(const char *s1, const char *s2);
void			ft_putstr_fd(char *s, int fd);
long			ft_atoi(const char *str);
double			ft_atof(const char *str);
int				ft_strlen(char *str);
int				ft_isdigit(int c);
#endif
