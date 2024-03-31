/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 04:46:38 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/30 05:21:21 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_sln(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_error(void)
{
	write(1, "error\n", 7);
	exit(1);
}

int	ft_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] == 46)
		{
			j++;
			i++;
		}
		if (j == 2 || str[0] == 46 || str[0] == '\0')
			ft_error();
		if (str[i] >= 58 || str[i] <= 47)
			return (1);
		i++;
	}
	return (0);
}

double	ft_handelf(char *str)
{
	int		flag;
	double	r;
	double	dive;

	dive = 10;
	r = 0;
	flag = 0;
	while ((*str >= '0' && *str <= '9') || *str == '.')
	{
		if (*str == '.' && flag == 0)
		{
			flag = 1;
			str++;
		}
		if (flag == 0)
			r = r * 10.0 + (*str - '0');
		else
		{
			r = r + ((*str - '0') / dive);
			dive *= 10;
		}
		str++;
	}
	return (r);
}

double	ft_atof(char *str)
{
	double	s;
	double	r;

	s = 1;
	r = 0;
	if (ft_check(str))
		ft_error();
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (str[0] == '\0' || *str == '\0')
		ft_error();
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	r = ft_handelf(str);
	return (r * s);
}
