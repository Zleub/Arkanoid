/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 04:20:46 by adebray           #+#    #+#             */
/*   Updated: 2015/05/02 06:12:12 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

static void error_callback(int error, const char* description)
{
	(void)error;
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == LEFT && g_player.vertex.shape.V4f.x > -1.3)
		g_player.vertex.shape.V4f.x -= 0.1;
	if (key == RIGHT && g_player.vertex.shape.V4f.x + g_player.vertex.shape.V4f.width < 1.2)
		g_player.vertex.shape.V4f.x += 0.1;
}

GLFWwindow*		init(void)
{
	GLFWwindow		*window;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	return (window);
}
