#ifndef ISOENGINE_RENDERER_HPP
#define ISOENGINE_RENDERER_HPP

#include <glad/glad.h>

#include "rectangle.hpp"

class Renderer {
public:
	static void initialize() {
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
	}

	static void draw(const Rectangle& rectangle);

private:
	static uint32_t EBO;
	static uint32_t VAO;
	static uint32_t VBO;
};

#endif