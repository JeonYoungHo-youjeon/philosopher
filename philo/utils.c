/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:23:02 by youjeon           #+#    #+#             */
/*   Updated: 2022/05/13 16:47:30 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *msg, int errno)
{
	printf("%s : %d\n", msg, errno);
	return (errno);
}

long long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long long	result;
	int			np;
	int			chker;

	result = 0;
	np = 1;
	chker = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		np = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		chker++;
		if ((result < 0 || chker > 19) && np == 1)
			return (-1);
		else if ((result < 0 || chker > 19) && np == -1)
			return (-1);
		str++;
	}
	return (result * np);
}
