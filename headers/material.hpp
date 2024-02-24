#ifndef ISOENGINE_MATERIAL_HPP
#define ISOENGINE_MATERIAL_HPP

#include <glm/vec3.hpp>

#include <memory>

#include "shader.hpp"

struct Material {
	Material(const glm::vec3& color, const std::shared_ptr<Shader>& shader) : color(color), shader(shader) {}
	Material(const Material&) = default;
	Material(Material&&) = default;
	virtual ~Material() = default;

	glm::vec3 color;
	std::shared_ptr<Shader> shader;
};

#endif