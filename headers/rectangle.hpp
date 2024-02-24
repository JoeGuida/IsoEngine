#ifndef ISOENGINE_RECTANGLE_HPP
#define ISOENGINE_RECTANGLE_HPP

#include <array>

class Rectangle {
public:
	Rectangle(float size) : width(size), height(size) 
	{
		vertices = {
			-width / 2.0f,  height / 2.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, 0.0f,
			-width / 2.0f, -height / 2.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, 0.0f
		};
		indices = { 0, 1, 2, 2, 3, 1 };
	}
	Rectangle(float width, float height) : width(width), height(height) 
	{
		vertices = {
			-width / 2.0f,  height / 2.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, 0.0f,
			-width / 2.0f, -height / 2.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, 0.0f
		};
		indices = { 0, 1, 2, 2, 3, 1 };
	}
	Rectangle(const Rectangle&) = default;
	Rectangle(Rectangle&&) = default;
	virtual ~Rectangle() = default;

	std::array<float, 12> get_vertices() const { return vertices; }
	std::array<uint32_t, 6> get_indices() const { return indices; }

private:
	float width;
	float height;
	std::array<float, 12> vertices;
	std::array<uint32_t, 6> indices;
};

#endif