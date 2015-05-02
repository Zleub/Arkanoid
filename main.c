/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 03:47:03 by adebray           #+#    #+#             */
/*   Updated: 2015/05/02 08:06:54 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void			update(void)
{
	glfwPollEvents();
	updateEntityList();
}

void			draw(GLFWwindow *window)
{
	float ratio;
	int width, height;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	// drawVertex4f(&(g_player.vertex.shape.V4f));
	// drawCircle(-0.8f, 0.2f, 0.05f);

	drawEntityList();

	glfwSwapBuffers(window);
	glfwPollEvents();
}

int				main(void)
{
	GLFWwindow	*window;

	g_entity = NULL;

	g_player.vertex.type = V4;
	g_player.vertex.shape.V4f.x = 0.0;
	g_player.vertex.shape.V4f.y = -0.8;
	g_player.vertex.shape.V4f.width = 0.6;
	g_player.vertex.shape.V4f.height = 0.1;

	addEntity(&g_player.vertex);

	newBall(0.2, -0.2, 0.05);
	newBall(0.6, -0.0, 0.05);

	window = init();
	while (!glfwWindowShouldClose(window))
	{
		update();
		draw(window);
		printEntityList();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
