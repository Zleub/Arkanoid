/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lua.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:27:34 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:33:48 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void		lexec(lua_State *l, char *str)
{
	lerror(l, luaL_loadbuffer(l, str, ft_strlen(str), "line")
		|| lua_pcall(l, 0, 0, 0));
}

double		lgetint(lua_State *l, char *index)
{
	double	tmp;

	lua_pushstring(l, index);
	lua_gettable(l, -2);
	if (!lua_isnumber(l, -1))
	{
		write(2, "Error, not integer in level\n", 28);
		exit(EXIT_FAILURE);
	}
	tmp = (double)lua_tonumber(l, -1);
	lua_pop(l, 1);
	return (tmp);
}

char		*lgetstring(lua_State *l, char *index)
{
	char	*tmp;

	tmp = NULL;
	lua_pushstring(l, index);
	lua_gettable(l, -2);
	if (!lua_isstring(l, -1) && !lua_isnil(l, -1))
	{
		write(2, "Error, not type in level\n", 28);
		exit(EXIT_FAILURE);
	}
	if (!lua_isnil(l, -1))
		tmp = (char*)lua_tostring(l, -1);
	lua_pop(l, 1);
	return (tmp);
}

void		lgetbrick(lua_State *l, int index)
{
	t_entity	*tmp;

	lua_pushnumber(l, index);
	lua_gettable(l, -2);
	if (!lua_istable(l, -1))
	{
		lua_pop(l, 1);
		return ;
	}
	tmp = newbrick(lgetint(l, "x"),
		lgetint(l, "y"), lgetint(l, "width"), lgetint(l, "height"));
	if (!ft_strcmp(lgetstring(l, "type"), "BRICK_INFIN"))
	{
		tmp->typegame = BRICK_INFIN;
		g_player.brick_nbr -= 1;
	}
	if (!ft_strcmp(lgetstring(l, "type"), "BRICK_OVERTIME"))
	{
		tmp->typegame = BRICK_OVERTIME;
		tmp->lives = 3;
	}
	lua_pop(l, 1);
	lgetbrick(l, index + 1);
}

void		lgetlevel(lua_State *l, int index)
{
	lua_pushnumber(l, index);
	lua_gettable(l, -2);
	if (lua_istable(l, -1))
	{
		lgetbrick(l, 1);
	}
	lua_pop(g_l, 1);
}
