/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 09:39:04 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:47:00 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>
#include <limits.h>

void		linit(void)
{
	g_l = luaL_newstate();
	luaL_openlibs(g_l);
	lexec(g_l, "levels = {}");
	lexec(g_l, "table.insert(levels, require 'levels.lvl_1')");
	lexec(g_l, "table.insert(levels, require 'levels.lvl_2')");
	lexec(g_l, "table.insert(levels, require 'levels.lvl_3')");
	lua_getglobal(g_l, "levels");
	if (!lua_istable(g_l, -1))
		error("`levels' is not a valid color table\n");
	lua_len(g_l, -1);
	if (!lua_isnumber(g_l, -1))
	{
		write(2, "Error, not len integer in level\n", 28);
		exit(EXIT_FAILURE);
	}
	g_player.level_nbr = (int)lua_tonumber(g_l, -1);
	lua_pop(g_l, 1);
	lgetlevel(g_l, 1);
}

void		lerror(lua_State *l, int error)
{
	const char	*message;

	if (error)
	{
		message = lua_tostring(l, -1);
		write(2, message, ft_strlen(message));
		lua_pop(l, 1);
	}
}

void		playercollide(t_entity *e, GLfloat i)
{
	int		angle;
	float	tmp;

	if ((int)(tmp = (i - g_player.vertex.shape.v4f.width / 2) * 50) != 0)
		angle = rand() % (int)(tmp * 10);
	if (i < g_player.vertex.shape.v4f.width / 2)
	{
		if (rand() % 2 == 0 && e->direction.x < 75)
			e->direction.x += angle;
		else
			e->direction.x -= angle;
		if (e->direction.x > 0)
			e->direction.x *= -1;
	}
	if (i >= g_player.vertex.shape.v4f.width / 2)
	{
		if (rand() % 2 == 0 && e->direction.x < 75)
			e->direction.x += angle;
		else
			e->direction.x -= angle;
		if (e->direction.x < 0)
			e->direction.x *= -1;
	}
}
