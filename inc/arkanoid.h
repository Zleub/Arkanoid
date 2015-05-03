/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 03:47:52 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:40:39 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <GLFW/glfw3.h>

# include <libft.h>
# include <ft_printf.h>
# include <time.h>

# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>

# define RATE 0.0002
# define GRAIN 0.0001
# define FT_M_PI 3.14116

enum						e_keys
{
	UP = 265,
	LEFT = 263,
	DOWN = 264,
	RIGHT = 262
};

typedef struct s_vertex4f	t_vertex4f;

struct						s_vertex4f
{
	GLfloat					x;
	GLfloat					y;
	GLfloat					width;
	GLfloat					height;
};

typedef struct s_vertex3f	t_vertex3f;

struct						s_vertex3f
{
	GLfloat					x;
	GLfloat					y;
	GLfloat					radius;
};

typedef struct s_vertex2f	t_vertex2f;

struct						s_vertex2f
{
	GLfloat					x;
	GLfloat					y;
};

typedef	union u_vertexf		t_vertexf;

union						u_vertexf
{
	t_vertex2f				v2f;
	t_vertex3f				v3f;
	t_vertex4f				v4f;
};

enum						e_types
{
	V2,
	V3,
	V4
};

enum						e_typesgame
{
	PLAYER,
	WALL,
	BALL,
	BRICK_INFIN,
	BRICK_OVERTIME,
	BRICK
};

typedef struct s_color		t_color;

struct						s_color
{
	GLfloat					red;
	GLfloat					green;
	GLfloat					blue;
};

typedef struct s_entity		t_entity;

struct						s_entity
{
	int						(*update)(t_entity*);
	t_vertex2f				direction;
	t_vertexf				shape;
	int						type;
	int						typegame;
	int						lives;
	t_color					color;
};

typedef struct s_entitylist	t_entitylist;

struct						s_entitylist
{
	t_entity				*content;
	t_entitylist			*next;
};

void						playercollide(t_entity *e, GLfloat i);
int							bottomcollide(t_entity *e, t_entitylist *tmp,
											t_vertex3f *circle);
int							leftcollide(t_entity *e, t_entitylist *tmp,
											t_vertex3f *circle);
int							upcollide(t_entity *e, t_entitylist *tmp,
											t_vertex3f *circle);
int							rightcollide(t_entity *e, t_entitylist *tmp,
											t_vertex3f *circle);
void						addentity(t_entity *new);
void						removeentity(t_entity *e);
void						printentity(t_entity *e);
void						printentitylist(void);
void						drawentitylist(void);
void						updateentitylist(void);
void						removeentitylevel(void);

GLFWwindow					*init(void);
void						error(char *error);
t_entity					*newbrick(GLfloat x, GLfloat y,
										GLfloat width, GLfloat height);
void						newbrickovertime(GLfloat x, GLfloat y,
												GLfloat width, GLfloat height);
void						newwall(GLfloat x, GLfloat y,
										GLfloat width, GLfloat height);
void						newball(GLfloat x, GLfloat y, GLfloat radius);

typedef struct s_player		t_player;

struct						s_player
{
	t_entity				vertex;
	int						score;
	int						level;
	int						level_nbr;
	int						brick_nbr;
};

typedef	struct s_ball		t_ball;

struct						s_ball
{
	t_entity				vertex;
};

void						drawvertex4f(t_vertex4f *v);
void						drawrect(GLfloat x, GLfloat y,
										GLfloat width, GLfloat height);
void						drawcircle(GLfloat x, GLfloat y, GLfloat radius);
void						drawlives(void);
void						drawovertime(t_entity *e);
void						drawscore(int i);

double						ft_cos(double angle);
double						ft_sin(double angle);

t_player					g_player;
t_entitylist				*g_entity;
lua_State					*g_l;

void						linit(void);
void						lexec(lua_State *l, char *str);
void						lgetlevel(lua_State *l, int index);
void						lerror(lua_State *l, int error);

#endif
