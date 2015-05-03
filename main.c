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
#include <time.h>

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
	g_player.vertex.shape.V4f.width = 0.45;
	g_player.vertex.shape.V4f.height = 0.06;

	addEntity(&g_player.vertex);

//	newBall(0, 1, 0.02);
//	newBall(0.6, -0.0, 0.02);
	newWall(-0.95, -0.95, 1.8, 0.01);
	newWall(-0.95, -0.95, 0.02, 1.9);
	newWall(0.95, -0.95, 0.02, 1.9);
	newWall(-0.95, 0.95, 1.9, 0.02);
	// newWall(-0.9, 0.9, 1.95, 0.2);
//	newWall(0.9, 0.9, 2, 0.01);

	window = init();
	srand(time(NULL));
	while (!glfwWindowShouldClose(window))
	{
		if (!(rand() % 100))
			newBall((rand() % 3) - 1, 1, 0.02);
		update();
		draw(window);
		printEntityList();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
