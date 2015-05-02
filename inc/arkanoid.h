/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 03:47:52 by adebray           #+#    #+#             */
/*   Updated: 2015/05/02 06:04:58 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <GLFW/glfw3.h>

# include <ft_printf.h>

/*\  NOT MANDATORY INCLUDES //*/

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/**
 *	Global Comment
 *
 *		Take care /!\
 *		Global vars a declared at bottom:
 *
 *		t_player		g_player;
 *		t_EntityList	*g_entity;
 *
 *		. . .
 *
 *		Everything is an Entity
 *			possess a shape (Vertexf->)
 *			possess a type (VertexXf)
 */

/*\  GLWF PURPOSE //*/

enum						e_keys
{
	UP = 265,
	LEFT = 263,
	DOWN = 264,
	RIGHT = 262
};

/*\  COLLISION PURPOSE //*/

/**
 *	A t_Vertex4f is a 4 float quad
 */
typedef struct s_Vertex4f	t_Vertex4f;

struct						s_Vertex4f
{
	GLfloat					x;
	GLfloat					y;
	GLfloat					width;
	GLfloat					height;
};

/**
 *	A t_Vertex3f is a 3 float circle
 */
typedef struct s_Vertex3f	t_Vertex3f;

struct						s_Vertex3f
{
	GLfloat					x;
	GLfloat					y;
	GLfloat					radius;
};

/**
 *	A t_Vertex3f is a 2 float direction
 */
typedef struct s_Vertex2f	t_Vertex2f;

struct						s_Vertex2f
{
	GLfloat					x;
	GLfloat					y;
};

/*\  Entity PURPOSE //*/

/**
 *	Practial union between Vertex to create
 *		ENTITY abstract type
 */
typedef	union u_Vertexf		t_Vertexf;

union						u_Vertexf
{
	t_Vertex2f				V2f;
	t_Vertex3f				V3f;
	t_Vertex4f				V4f;
};

/**
 *	Entity types enum
 */
enum						e_types
{
	V2,
	V3,
	V4
};

/**
 *	Entity basic struct
 */
typedef struct s_Entity		t_Entity;

struct						s_Entity
{
	t_Vertexf				shape;
	int						type;
};

/**
 *	Entity basic list (globalized)
 */
typedef struct s_EntityList	t_EntityList;

struct						s_EntityList
{
	t_Entity				*content;
	t_EntityList			*next;
};

void						addEntity(t_Entity *new);
void						printEntityList(void);

/*\  GAME PURPOSE //*/

/**
 *	Basic info for player :
 *	vertex stand for the quad use both for
 *		drawing && collision
 */
typedef struct s_player		t_player;

struct						s_player
{
	t_Entity				vertex;
};

GLFWwindow*					init(void);

/*\  DRAWING PURPOSE //*/

void						drawVertex4f(t_Vertex4f *_v);
void						drawRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
void						drawCircle(GLfloat x, GLfloat y, GLfloat radius);

t_player					g_player;
t_EntityList				*g_entity;

#endif
