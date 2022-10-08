/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:04:48 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/08 18:30:00 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "limits.h"

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
			return (INT_OVERFLOW);
		i++;
	}
	return (res * neg);
}

// double	ft_atof(const char *str)
// {
// 	double	res;
// 	double	res2;
// 	char	*c;
// 	int		len;

// 	c = (char *)str;
// 	res = (double)ft_atoi(c);
// 	while (*c && *c != '.')
// 		c++;
// 	if (*c == '.')
// 		c++;
// 	res2 = (double)ft_atoi(c);
// 	len = ft_strlen(c);
// 	while (len--)
// 		res2 /= 10;
// 	if (res >= 0)
// 		return (res + res2);
// 	else
// 		return (res - res2);
// }

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