#ifndef ISOENGINE_TRANSFORM_HPP
#define ISOENGINE_TRANSFORM_HPP

#include <glm/vec3.hpp>

struct Transform {
	Transform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& local_scale) : 
		position(position),
		rotation(rotation),
		local_scale(local_scale) {}
	Transform(const glm::vec3& position, const glm::vec3& rotation) : 
		position(position),
		rotation(rotation),
		local_scale(glm::vec3(1.0f)) {}
	Transform(const glm::vec3& position) :
		position(position),
		rotation(glm::vec3(0.0f)),
		local_scale(glm::vec3(1.0f)) {}
	Transform(const Transform&) = default;
	Transform(Transform&&) = default;
	virtual ~Transform() = default;

	void translate(const glm::vec3& to);
	void rotate(float amount);
	void scale(const glm::vec3& amount);

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 local_scale;
};

#endif