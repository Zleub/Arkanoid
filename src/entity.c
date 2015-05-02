/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:21:28 by adebray           #+#    #+#             */
/*   Updated: 2015/05/02 05:26:55 by adebray          ###   ########.fr       */
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
