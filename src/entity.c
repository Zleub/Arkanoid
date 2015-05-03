/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:21:28 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:33:47 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

static void			drawentity(t_entity *e)
{
	glColor3f(e->color.red, e->color.green, e->color.blue);
	if (e->type == V2)
		;
	if (e->type == V3)
		drawcircle(e->shape.v3f.x, e->shape.v3f.y, e->shape.v3f.radius);
	if (e->type == V4)
	{
		if (e->typegame == BRICK_OVERTIME)
			drawovertime(e);
		else
			drawvertex4f(&e->shape.v4f);
	}
	glColor3f(1, 1, 1);
}

void				drawentitylist(void)
{
	t_entitylist	*tmp;

	tmp = g_entity;
	while (tmp)
	{
		drawentity(tmp->content);
		tmp = tmp->next;
	}
}

static int			updateentity(t_entity *e)
{
	if (e->type == V2)
		;
	if (e->type == V3)
		return (e->update(e));
	if (e->type == V4)
		;
	return (1);
}

void				updateentitylist(void)
{
	t_entitylist	*tmp;

	tmp = g_entity;
	while (tmp)
	{
		if (!updateentity(tmp->content))
			return ;
		tmp = tmp->next;
	}
}
