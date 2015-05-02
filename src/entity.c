/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:21:28 by adebray           #+#    #+#             */
/*   Updated: 2015/05/02 07:27:00 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void			addEntity(t_Entity *new)
{
	static t_EntityList		*last;

	if (!g_entity)
	{
		if (!(g_entity = (t_EntityList*)malloc(sizeof(t_EntityList))))
			exit(EXIT_FAILURE);
		g_entity->content = new;
		g_entity->next = NULL;
		last = g_entity;
	}
	else
	{
		if (!(last->next = (t_EntityList*)malloc(sizeof(t_EntityList))))
			exit(EXIT_FAILURE);
		last->next->content = new;
		last->next->next = NULL;
		last = last->next;
	}
}

void			printEntity(t_Entity *e)
{
	if (e->type == V2)
		printf("Vectex2f:\n\tx:%f\n\ty:%f\n", e->shape.V2f.x, e->shape.V2f.y);
	if (e->type == V3)
		printf("Vectex3f:\n\tx:%f\n\ty:%f\n\tradius:%f\n", e->shape.V3f.x, e->shape.V3f.y, e->shape.V3f.radius);
	if (e->type == V4)
		printf("Vectex4f:\n\tx:%f\n\ty:%f\n\twidth:%f\n\theight%f\n", e->shape.V4f.x, e->shape.V4f.y, e->shape.V4f.width, e->shape.V4f.height);
}

void			printEntityList(void)
{
	t_EntityList	*tmp;

	tmp = g_entity;
	while (tmp)
	{
		printEntity(tmp->content);
		tmp = tmp->next;
	}
}

void			drawEntity(t_Entity *e)
{
	if (e->type == V2)
		// printf("Vectex2f:\n\tx:%f\n\ty:%f\n", e->shape.V2f.x, e->shape.V2f.y);
		;
	if (e->type == V3)
		drawCircle(e->shape.V3f.x, e->shape.V3f.y, e->shape.V3f.radius);
	if (e->type == V4)
		drawVertex4f(&e->shape.V4f);
}

void			drawEntityList(void)
{
	t_EntityList	*tmp;

	tmp = g_entity;
	while (tmp)
	{
		drawEntity(tmp->content);
		tmp = tmp->next;
	}
}

void			updateEntity(t_Entity *e)
{
	if (e->type == V2)
		;
	if (e->type == V3)
		e->_update(e);
	if (e->type == V4)
		;
}

void			updateEntityList(void)
{
	t_EntityList	*tmp;

	tmp = g_entity;
	while (tmp)
	{
		updateEntity(tmp->content);
		tmp = tmp->next;
	}
}
