/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:41:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/28 16:17:24 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "tools.h"

t_bool		ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
static void	ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);

#endif
