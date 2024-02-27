#ifndef ISOENGINE_MATERIAL_HPP
#define ISOENGINE_MATERIAL_HPP

#include <glm/vec3.hpp>

#include <memory>

#include "shader.hpp"
#include "texture.hpp"

struct Material {
	Material(const Texture& texture, const std::shared_ptr<Shader>& shader) : texture(texture), shader(shader) {}
	Material(const Material&) = default;
	Material(Material&&) = default;
	virtual ~Material() = default;

	Texture texture;
	std::shared_ptr<Shader> shader;
};

#endif