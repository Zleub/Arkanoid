/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 03:47:26 by adebray           #+#    #+#             */
/*   Updated: 2015/05/02 04:54:45 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void	drawVertex4f(t_Vertex4f *_v)
{
	drawRect(_v->x, _v->y, _v->width, _v->height);
}

void	drawRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 128;

	GLfloat twicePi = 2.0f * 3.14;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	i = 0;
	while(i <= triangleAmount)
	{
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
		i += 1;
	}
	glEnd();
}
