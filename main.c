/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 03:47:03 by adebray           #+#    #+#             */
/*   Updated: 2015/05/03 22:48:00 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void			error(char *error)
{
	write(2, error, ft_strlen(error));
}

void			update(GLFWwindow *window)
{
	if (g_player.level > g_player.level_nbr)
		exit(EXIT_SUCCESS);
	if (g_player.brick_nbr == 0)
	{
		removeentitylevel();
		g_player.level += 1;
		lgetlevel(g_l, g_player.level);
		return ;
	}
	if (glfwGetKey(window, LEFT) && g_player.vertex.shape.v4f.x > -0.85)
		g_player.vertex.shape.v4f.x -= 0.05;
	if (glfwGetKey(window, RIGHT) &&
		g_player.vertex.shape.v4f.x + g_player.vertex.shape.v4f.width < 0.86)
		g_player.vertex.shape.v4f.x += 0.05;
	updateentitylist();
	glfwPollEvents();
}

void			draw(GLFWwindow *window)
{
	float		ratio;
	int			width;
	int			height;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	drawentitylist();
	drawlives();
	drawscore(g_player.score);
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void			ginit(void)
{
	srand(time(NULL));
	g_entity = NULL;
	g_player.score = 0;
	g_player.brick_nbr = 0;
	g_player.level = 1;
	g_player.vertex.lives = 3;
	g_player.vertex.type = V4;
	g_player.vertex.typegame = PLAYER;
	g_player.vertex.shape.v4f.x = -0.2;
	g_player.vertex.shape.v4f.y = -0.8;
	g_player.vertex.shape.v4f.width = 0.4;
	g_player.vertex.shape.v4f.height = 0.02;
	g_player.vertex.color.red = 1.0;
	g_player.vertex.color.green = 1.0;
	g_player.vertex.color.blue = 1.0;
	addentity(&g_player.vertex);
	newball(0, 0, 0.02);
	newwall(0.92, -0.9, 0.02, 1.8);
	newwall(-0.9, 0.9, 1.8, 0.02);
	newwall(-0.9, -0.9, 0.02, 1.8);
}

int				main(void)
{
	GLFWwindow	*window;

	ginit();
	linit();
	window = init();
	while (!glfwWindowShouldClose(window))
	{
		update(window);
		draw(window);
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
