#include "renderer.hpp"

uint32_t Renderer::EBO;
uint32_t Renderer::VAO;
uint32_t Renderer::VBO;

void Renderer::draw(const Rectangle& rectangle, const Material& material) {
	std::array<float, 20> vertices = rectangle.get_vertices();
	std::array<uint32_t, 6> indices = rectangle.get_indices();

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(float), vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glm::mat4 model = glm::mat4(1.0f);
	material.shader->set("model", model);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}