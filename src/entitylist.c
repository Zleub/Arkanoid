/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entitylist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 02:35:54 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:58:07 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

t_entitylist		*getentitylast(void)
{
	t_entitylist	*tmp;

	tmp = g_entity;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void				addentity(t_entity *new)
{
	t_entitylist	*last;

	if (!g_entity)
	{
		if (!(g_entity = (t_entitylist*)malloc(sizeof(t_entitylist))))
			exit(EXIT_FAILURE);
		g_entity->content = new;
		g_entity->next = NULL;
	}
	else
	{
		last = getentitylast();
		if (!(last->next = (t_entitylist*)malloc(sizeof(t_entitylist))))
			exit(EXIT_FAILURE);
		last->next->content = new;
		last->next->next = NULL;
	}
}

void				removeentityin(t_entity *e)
{
	t_entitylist	*tmp;
	t_entitylist	*tmp2;

	tmp = g_entity;
	while (tmp)
	{
		if (tmp->next && tmp->next->content == e &&
				tmp->next->content->typegame != WALL &&
				tmp->next->content->typegame != PLAYER)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			free(tmp2->content);
			free(tmp2);
		}
		tmp = tmp->next;
	}
}

void				removeentity(t_entity *e)
{
	t_entitylist	*tmp;

	tmp = g_entity;
	if (tmp->content == e && tmp->content->typegame != WALL
		&& tmp->content->typegame != PLAYER)
	{
		g_entity = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	else
		removeentityin(e);
}

void				removeentitylevel(void)
{
	t_entitylist	*tmp;

	tmp = g_entity;
	while (tmp)
	{
		if (tmp->content->typegame != PLAYER &&
			tmp->content->typegame != BALL &&
			tmp->content->typegame != WALL)
			removeentity(tmp->content);
		tmp = tmp->next;
	}
}
