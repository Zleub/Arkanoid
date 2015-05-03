/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 17:56:10 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 19:08:42 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

static double	taylor_cos(double angle)
{
	int		step;
	double	fact;
	double	square_angle;
	double	ret;

	square_angle = angle * angle;
	angle = 1;
	step = 0;
	fact = 1;
	ret = 1;
	while (step++ < 10)
	{
		angle = angle * -1 * square_angle;
		fact = fact * 2 * step * (2 * step - 1);
		ret = ret + angle / fact;
	}
	return (ret);
}

double			ft_cos(double angle)
{
	int	sign;

	sign = 1;
	if (angle < 0)
		angle *= -1;
	if (angle == 0)
		return (1);
	else if (angle == FT_M_PI / 2)
		return (0);
	else if (angle > FT_M_PI / 2)
	{
		angle = FT_M_PI - angle;
		sign = -1;
	}
	return (sign * taylor_cos(angle));
}
