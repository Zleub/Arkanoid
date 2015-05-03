/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 21:03:06 by mtauffli          #+#    #+#             */
/*   Updated: 2015/05/03 22:33:49 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void		newwall(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
	t_entity		*new;

	if (!(new = (t_entity*)malloc(sizeof(t_entity))))
		exit(EXIT_FAILURE);
	new->direction.x = 0;
	new->direction.y = 0;
	new->type = V4;
	new->typegame = WALL;
	new->shape.v4f.x = x;
	new->shape.v4f.y = y;
	new->shape.v4f.width = width;
	new->shape.v4f.height = height;
	new->update = NULL;
	new->color.red = 1.0;
	new->color.green = 1.0;
	new->color.blue = 1.0;
	addentity(new);
}
