/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:46:22 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/02 19:36:30 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "init.h"
#include "tools.h"
#include "utils.h"

#include <unistd.h>

t_bool	allowed_string(char *str)
{
	int	i;

	i = 0;
	if (*str == 0)
		return (FALSE);
	if (str[0] == '-')
		i++;
	if (ft_isdigit(str[0]) && str[1] == '.')
		i += 2;
	printf("str : %s\n", str);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	parse_args(t_data *data, int argc, char **argv)
{
	if (argc < 2)
		return (exit_error(ERR_ARG_LOW));
	if ((ft_strcmp(argv[1], "Mandelbrot") || ft_strcmp(argv[1], "Multibrot"))
		&& argc > 2)
		return (exit_error(ERR_ARG_HIGH));
	if ((ft_strcmp(argv[1], "Julia") && (argc == 3) || (argc > 4)))
		return (exit_error(ERR_ARG_HIGH));
	if (ft_strcmp(argv[1], "Julia"))
		init_julia(data, argv, argc);
}
