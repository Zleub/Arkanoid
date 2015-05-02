/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:21:28 by adebray           #+#    #+#             */
/*   Updated: 2015/05/02 05:57:07 by adebray          ###   ########.fr       */
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
		last = g_entity;
	}
	else
	{
		if (!(last->next = (t_EntityList*)malloc(sizeof(t_EntityList))))
			exit(EXIT_FAILURE);
		last->next->content = new;
		last = last->next;
	}
}

void			printEntity(t_Entity *e)
{
	if (e->type == V2f)
		ft_printf("Vectex2f:\n\tx:%d\n\ty:%d\n", e->shape->x, e->shape->y);
	if (e->type == V3f)
		ft_printf("Vectex3f:\n\tx:%d\n\ty:%dradius:%d\n", e->shape->x, e->shape->y, e->shape->radius);
	if (e->type == V4f)
		ft_printf("Vectex4f:\n\tx:%d\n\ty:%dwidth:%d\n\theight%d\n", e->shape->x, e->shape->y, e->shape->width, e->shape->height);
}

void			printEntityList(void)
{
	t_EntityList	*tmp;


}
