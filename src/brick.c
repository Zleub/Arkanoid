/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 18:00:55 by mtauffli          #+#    #+#             */
/*   Updated: 2015/05/03 22:33:46 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

int			updatebrick(t_entity *e)
{
	if (e->typegame == BRICK_INFIN)
		return (1);
	e->lives -= 1;
	if (e->lives <= 0)
	{
		g_player.brick_nbr -= 1;
		removeentity(e);
	}
	if (e->typegame == BRICK)
		g_player.score += 10;
	else if (e->typegame == BRICK_OVERTIME)
		g_player.score += 7;
	return (1);
}

t_entity	*newbrick(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
	t_entity		*new;

	g_player.brick_nbr += 1;
	if (!(new = (t_entity*)malloc(sizeof(t_entity))))
		exit(EXIT_FAILURE);
	new->direction.x = 0;
	new->direction.y = 0;
	new->type = V4;
	new->lives = 1;
	new->typegame = BRICK;
	new->shape.v4f.x = x;
	new->shape.v4f.y = y;
	new->shape.v4f.width = width;
	new->shape.v4f.height = height;
	new->update = updatebrick;
	new->color.red = 0.3 + (rand() % 7 + 0.0) / 10;
	new->color.green = 0.3 + (rand() % 7 + 0.0) / 10;
	new->color.blue = 0.3 + (rand() % 7 + 0.0) / 10;
	addentity(new);
	return (new);
}
