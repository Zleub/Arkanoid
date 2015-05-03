/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 01:29:59 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:33:46 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

static int			circlecollision(GLfloat x, GLfloat y, t_vertex3f v)
{
	GLfloat tmp1;
	GLfloat tmp2;
	GLfloat circle;

	tmp1 = x - v.x;
	tmp2 = y - v.y;
	circle = tmp1 * tmp1 + tmp2 * tmp2;
	if (circle > v.radius * v.radius)
		return (0);
	else
		return (1);
}

int					bottomcollide(t_entity *e, t_entitylist *tmp, t_vertex3f *c)
{
	GLfloat		tmp1;
	int			caca;

	tmp1 = 0;
	caca = 0;
	while (tmp1 < tmp->content->shape.v4f.width)
	{
		if (circlecollision(
			tmp1 + tmp->content->shape.v4f.x,
			tmp->content->shape.v4f.y, *c))
		{
			e->direction.y *= -1;
			caca = 1;
			break ;
		}
		tmp1 += GRAIN;
	}
	if (caca)
		return (1);
	return (0);
}

int					leftcollide(t_entity *e, t_entitylist *tmp, t_vertex3f *c)
{
	GLfloat		tmp1;
	int			caca;

	caca = 0;
	tmp1 = 0;
	while (tmp1 < tmp->content->shape.v4f.height)
	{
		if (circlecollision(
			tmp->content->shape.v4f.x,
			tmp1 + tmp->content->shape.v4f.y, *c))
		{
			e->direction.x *= -1;
			caca = 1;
			break ;
		}
		tmp1 += GRAIN;
	}
	if (caca)
		return (1);
	return (0);
}

int					upcollide(t_entity *e, t_entitylist *tmp, t_vertex3f *c)
{
	GLfloat		tmp1;
	int			caca;

	caca = 0;
	tmp1 = 0;
	while (tmp1 < tmp->content->shape.v4f.width)
	{
		if (circlecollision(
			tmp1 + tmp->content->shape.v4f.x,
			tmp->content->shape.v4f.y + tmp->content->shape.v4f.height,
			*c))
		{
			if (tmp->content == &g_player.vertex)
				playercollide(e, tmp1);
			else
				e->direction.y *= -1;
			caca = 1;
			break ;
		}
		tmp1 += GRAIN;
	}
	if (caca)
		return (1);
	return (0);
}

int					rightcollide(t_entity *e, t_entitylist *tmp, t_vertex3f *c)
{
	GLfloat		tmp1;
	int			caca;

	caca = 0;
	tmp1 = 0;
	while (tmp1 < tmp->content->shape.v4f.height)
	{
		if (circlecollision(
			tmp->content->shape.v4f.x + tmp->content->shape.v4f.width,
			tmp1 + tmp->content->shape.v4f.y, *c))
		{
			e->direction.x *= -1;
			caca = 1;
			break ;
		}
		tmp1 += GRAIN;
	}
	if (caca)
		return (1);
	return (0);
}
