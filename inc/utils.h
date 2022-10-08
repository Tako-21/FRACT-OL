/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:41:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/08 17:59:25 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "tools.h"

t_bool			ft_strcmp(const char *s1, const char *s2);
void			ft_putstr_fd(char *s, int fd);
double			ft_atoi(const char *str);
double			ft_atof(const char *str);
int				ft_strlen(char *str);
int				ft_isdigit(int c);
double			ft_atof_perso(char *str);
#endif
