/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:13:10 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/24 21:15:35 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "tools.h"
#include <stdlib.h>
#include <unistd.h>

t_bool	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	if (s1[i] == s2[i])
		return (TRUE);
	return (FALSE);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}
