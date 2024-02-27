#ifndef ISOENGINE_RECTANGLE_HPP
#define ISOENGINE_RECTANGLE_HPP

#include <array>

#include "material.hpp"
#include "transform.hpp"

class Rectangle {
public:
	Rectangle(float size, const Transform& transform, const Material& material) : 
		width(size), 
		height(size), 
		transform(transform), 
		material(material)
	{
		vertices = {
			-width / 2.0f,  height / 2.0f, 0.0f, 0.0f, 1.0f,
			 width / 2.0f,  height / 2.0f, 0.0f, 1.0f, 1.0f,
			-width / 2.0f, -height / 2.0f, 0.0f, 0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, 0.0f, 1.0f, 0.0f
		};
		indices = { 0, 1, 2, 2, 3, 1 };
	}
	Rectangle(float width, float height, const Transform& transform, const Material& material) : 
		width(width), 
		height(height), 
		transform(transform), 
		material(material)
	{
		vertices = {
			-width / 2.0f,  height / 2.0f, 0.0f, 0.0f, 1.0f,
			 width / 2.0f,  height / 2.0f, 0.0f, 1.0f, 1.0f,
			-width / 2.0f, -height / 2.0f, 0.0f, 0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, 0.0f, 1.0f, 0.0f
		};
		indices = { 0, 1, 2, 2, 3, 1 };
	}
	Rectangle(const Rectangle&) = default;
	Rectangle(Rectangle&&) = default;
	virtual ~Rectangle() = default;

	std::array<float, 20> get_vertices() const { return vertices; }
	std::array<uint32_t, 6> get_indices() const { return indices; }

	Material material;
	Transform transform;

private:
	float width;
	float height;
	std::array<float, 20> vertices;
	std::array<uint32_t, 6> indices;
};

#endif