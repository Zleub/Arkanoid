/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 08:55:20 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:46:22 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void		drawint0(int i, GLfloat x, GLfloat y)
{
	if (i == 0)
	{
		drawrect(x + 0, y + 0.1, 0.1, 0.01);
		drawrect(x + 0, y + 0, 0.1, 0.01);
		drawrect(x + 0.1, y + 0, 0.01, 0.1);
		drawrect(x + 0, y + 0, 0.01, 0.1);
	}
}

void		drawint3(int i, GLfloat x, GLfloat y)
{
	if (i == 7)
	{
		drawrect(x + 0.1, y + 0, 0.01, 0.1);
		drawrect(x + 0, y + 0.1, 0.1, 0.01);
	}
	if (i == 8)
	{
		drawrect(x + 0, y + 0.1, 0.1, 0.01);
		drawrect(x + 0, y + 0.05, 0.1, 0.01);
		drawrect(x + 0, y + 0, 0.1, 0.01);
		drawrect(x + 0.1, y + 0, 0.01, 0.1);
		drawrect(x + 0, y + 0, 0.01, 0.1);
	}
	if (i == 9)
	{
		drawrect(x + 0, y + 0.1, 0.1, 0.01);
		drawrect(x + 0, y + 0.05, 0.1, 0.01);
		drawrect(x + 0, y + 0, 0.1, 0.01);
		drawrect(x + 0.1, y + 0, 0.01, 0.1);
		drawrect(x + 0, y + 0.05, 0.01, 0.05);
	}
	drawint0(i, x, y);
}

void		drawint2(int i, GLfloat x, GLfloat y)
{
	if (i == 4)
	{
		drawrect(x + 0.1, y + 0, 0.01, 0.05);
		drawrect(x + 0, y + 0.02, 0.1, 0.01);
		drawrect(x, y + 0.02, 0.01, 0.08);
	}
	if (i == 5)
	{
		drawrect(x, y + 0.05, 0.1, 0.01);
		drawrect(x, y + 0.1, 0.1, 0.01);
		drawrect(x, y, 0.1, 0.01);
		drawrect(x, y + 0.05, 0.01, 0.05);
		drawrect(x + 0.1, y, 0.01, 0.05);
	}
	if (i == 6)
	{
		drawrect(x, y + 0.1, 0.1, 0.01);
		drawrect(x + 0, y + 0.05, 0.1, 0.01);
		drawrect(x, y, 0.1, 0.01);
		drawrect(x + 0.1, y, 0.01, 0.05);
		drawrect(x + 0, y, 0.01, 0.1);
	}
	drawint3(i, x, y);
}

void		drawint1(int i, GLfloat x, GLfloat y)
{
	if (i == 1)
		drawrect(x + 0, y + 0, 0.01, 0.1);
	if (i == 2)
	{
		drawrect(x, y + 0.05, 0.1, 0.01);
		drawrect(x, y + 0.1, 0.1, 0.01);
		drawrect(x, y, 0.1, 0.01);
		drawrect(x + 0.1, y + 0.05, 0.01, 0.05);
		drawrect(x, y, 0.01, 0.05);
	}
	if (i == 3)
	{
		drawrect(x, y + 0.1, 0.1, 0.01);
		drawrect(x + 0.05, y + 0.05, 0.05, 0.01);
		drawrect(x, y, 0.1, 0.01);
		drawrect(x + 0.1, y, 0.01, 0.1);
	}
	drawint2(i, x, y);
}

void		drawscore(int i)
{
	static int	test;

	if (i > 9)
	{
		drawscore(i / 10);
		test += 1;
		drawint1(i % 10, 0.12 * test, 0.75);
	}
	else
	{
		test = 0;
		drawint1(i, 0, 0.75);
	}
}
