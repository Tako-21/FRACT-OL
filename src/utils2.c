/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:04:48 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/09 19:28:29 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "limits.h"
#include "error.h"

double	ft_atoi(const char *str)
{
	int				i;
	double			res;
	int				neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res * neg > INT_MAX || res * neg < INT_MIN)
			return (exit_error(ERR_INT_OVERFLOW), 21);
		i++;
	}
	return (res * neg);
}

double	ft_atof_perso(char *str)
{
	double	res;
	double	int_res;
	int		len;

	int_res = ft_atoi(str);
	len = ft_strlen(str) - 1;
	res = 0.0;
	while (str[len] != '.')
	{
		res = res * 0.1 + 0.1 * (str[len] - 48);
		len--;
	}
	if (str[0] == '-')
		return (int_res - res);
	else
		return (int_res + res);
}
