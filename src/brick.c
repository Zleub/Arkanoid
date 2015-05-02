/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtauffli <mtauffli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 18:00:55 by mtauffli          #+#    #+#             */
/*   Updated: 2015/05/02 18:00:55 by mtauffli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>
/*
int			Collision(GLfloat x, GLfloat y, t_Vertex4f v)
{
	if (x >= v.x
		&& x < v.x + v.width
		&& y >= v.y
		&& y < v.y + v.height)
		return 1;
	else
		return 0;
}

int			BrickCollision(GLfloat x, GLfloat y, t_Vertex3f v)
{
	GLfloat tmp1;
	GLfloat tmp2;
	// if (v.x < 0)
	// 	tmp1 = x + v.x;
	// else
		tmp1 = (x + 1) - (v.x + 1);
	// if (v.y < 0)
	// 	tmp2 = y + v.y;
	// else
		tmp2 = (y + 1) - (v.y + 1);
	// printf("%f .. %f\n", tmp1, tmp2);
	GLfloat circle = tmp1 * tmp1 + tmp2 * tmp2;

	// printf("%f .. %f\n", circle, v.radius * v.radius);
	if (circle > v.radius * v.radius)
		return 0;
	else
		return 1;
}
*/
void		basicBrickUpdate(t_Entity * e)
{
	(void)e;
	printf("e update:\n");
	printEntity(e);

	t_EntityList *tmp;

	tmp = g_entity;
	// while (tmp)
	// {
	// 	if (tmp->content->type == V4)
	// 	{
	// 		GLfloat tmp1 = tmp->content->shape.V4f.x;
	// 		while (tmp1 < tmp->content->shape.V4f.width)
	// 		{
	// 			// printf("tmp1 : %f\n", tmp1);
	// 			GLfloat tmp2 = tmp->content->shape.V4f.y;
	// 			while (tmp2 < tmp->content->shape.V4f.height)
	// 			{
	// 				// printf("tmp2 : %f\n", tmp2);
	// 				if (BrickCollision(tmp1 + tmp->content->shape.V4f.x, tmp2 + tmp->content->shape.V4f.y, e->shape.V3f))
	// 					printf("collision\n");
	// 				tmp2 += 0.01;
	// 			}
	// 			tmp1 += 0.01;
	// 		}
	// 	}

	// 	tmp = tmp->next;
	// }

	e->shape.V3f.x += e->direction.x * 0.0001;
	e->shape.V3f.y += e->direction.y * 0.0001;
}


void		newBrick(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
	t_Entity		*new;

	if (!(new = (t_Entity*)malloc(sizeof(t_Entity))))
		exit(EXIT_FAILURE);
	new->direction.x = 0;
	new->direction.y = 0;
	new->type = V4;
	new->shape.V4f.x = x;
	new->shape.V4f.y = y;
	new->shape.V4f.width = width;
	new->shape.V4f.height = height;
	new->_update = basicBrickUpdate;
	addEntity(new);
}
