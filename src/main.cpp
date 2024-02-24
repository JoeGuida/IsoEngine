#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "rectangle.hpp"
#include "renderer.hpp"
#include "shader.hpp"

constexpr int SCREEN_WIDTH = 1920;
constexpr const int SCREEN_HEIGHT = 1080;
constexpr double ASPECT_RATIO = double(SCREEN_WIDTH) / double(SCREEN_HEIGHT);

bool is_wireframe = false;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* initialize();
void process_input(GLFWwindow* window, int key, int scancode, int action, int mods);
void toggle_wireframe();

int main() {
	GLFWwindow* window = initialize();
	Renderer::initialize();

	// --------------------------------------------------------------------------------------------
	// Compile Shaders
	// --------------------------------------------------------------------------------------------
	std::shared_ptr<Shader> default_shader = ShaderFactory::create("default");

	// --------------------------------------------------------------------------------------------
	// Create Materials
	// --------------------------------------------------------------------------------------------
	Material default_material(glm::vec3(0.0f, 0.0f, 1.0f), default_shader);

	// --------------------------------------------------------------------------------------------
	// Create Objects
	// --------------------------------------------------------------------------------------------
	Rectangle rectangle(0.5f);

	// --------------------------------------------------------------------------------------------
	// Render Loop
	// --------------------------------------------------------------------------------------------
	glm::mat4 projection = glm::ortho(-ASPECT_RATIO, ASPECT_RATIO, -1.0, 1.0);
	default_shader->set("projection", projection);
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Renderer::draw(rectangle, default_material);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

GLFWwindow* initialize() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create GLFW window and set callbacks
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Title", nullptr, nullptr);
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, process_input);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

	return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS) {
		toggle_wireframe();
	}
}

void toggle_wireframe() {
	is_wireframe = !is_wireframe;
	if (is_wireframe) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}