/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 03:47:26 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:33:47 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void		drawvertex4f(t_vertex4f *v)
{
	drawrect(v->x, v->y, v->width, v->height);
}

void		drawrect(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

void		drawcircle(GLfloat x, GLfloat y, GLfloat radius)
{
	int		i;
	int		triangleamount;
	GLfloat	twicepi;

	twicepi = 2.0f * 3.14;
	triangleamount = 128;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	i = 0;
	while (i <= triangleamount)
	{
		glVertex2f(
			x + (radius * ft_cos(i * twicepi / triangleamount)),
			y + (radius * ft_sin(i * twicepi / triangleamount)));
		i += 1;
	}
	glEnd();
}

void		drawlives(void)
{
	int		i;

	i = 0;
	while (i < g_player.vertex.lives)
	{
		drawrect(-1, 0.8 - (i + 0.0) / 10, 0.05, 0.05);
		i += 1;
	}
}

void		drawovertime(t_entity *e)
{
	t_vertex4f *v;

	v = &e->shape.v4f;
	drawrect(v->x, v->y, v->width, v->height);
	if (e->lives > 0)
	{
		if (e->lives == 3)
			glColor3f(1, 1, 1);
		if (e->lives == 2)
			glColor3f(0.6, 0.6, 0.6);
		if (e->lives == 1)
			glColor3f(0.3, 0.3, 0.3);
		drawrect(v->x, v->y, v->width, 0.01);
		drawrect(v->x, v->y + v->height - 0.01, v->width, 0.01);
		drawrect(v->x, v->y, 0.01, v->height);
		drawrect(v->x + v->width - 0.01, v->y, 0.01, v->height);
	}
}
