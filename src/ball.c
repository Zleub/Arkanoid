/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 07:09:21 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:37:05 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

static void			ondeath(t_entity *e)
{
	g_player.vertex.lives -= 1;
	if (g_player.vertex.lives <= -1)
		exit(EXIT_SUCCESS);
	newball(0, 0, 0.02);
	removeentity(e);
}

static int			ballcollision(t_entity *e, t_entitylist *tmp)
{
	t_vertex3f		prout;

	prout.x = e->shape.v3f.x + e->direction.x * RATE;
	prout.y = e->shape.v3f.y + e->direction.y * RATE;
	prout.radius = e->shape.v3f.radius;
	if (bottomcollide(e, tmp, &prout))
		return (1);
	else if (upcollide(e, tmp, &prout))
		return (1);
	else if (leftcollide(e, tmp, &prout))
		return (1);
	else if (rightcollide(e, tmp, &prout))
		return (1);
	else
		return (0);
}

int					basicballupdate(t_entity *e)
{
	t_entitylist	*tmp;

	tmp = g_entity;
	while (tmp)
	{
		if (tmp->content->type == V4)
		{
			if (ballcollision(e, tmp))
			{
				if (tmp->content->update)
					tmp->content->update(tmp->content);
				break ;
			}
		}
		tmp = tmp->next;
	}
	e->shape.v3f.x += e->direction.x * RATE;
	e->shape.v3f.y += e->direction.y * RATE;
	if (e->shape.v3f.y < -1.5)
	{
		ondeath(e);
		return (0);
	}
	return (1);
}

void				newball(GLfloat x, GLfloat y, GLfloat radius)
{
	t_ball			*new;

	if (!(new = (t_ball*)malloc(sizeof(t_ball))))
		exit(EXIT_FAILURE);
	new->vertex.direction.x = rand() % 100 - 75;
	new->vertex.direction.y = -100;
	new->vertex.type = V3;
	new->vertex.typegame = BALL;
	new->vertex.shape.v3f.x = x;
	new->vertex.shape.v3f.y = y;
	new->vertex.shape.v3f.radius = radius;
	new->vertex.update = basicballupdate;
	new->vertex.color.red = 1.0;
	new->vertex.color.green = 1.0;
	new->vertex.color.blue = 1.0;
	addentity(&new->vertex);
}
