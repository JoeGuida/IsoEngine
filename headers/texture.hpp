#ifndef ISOENGINE_TEXTURE_HPP
#define ISOENGINE_TEXTURE_HPP

#include <glad/glad.h>
#include <stb_image.h>

#include "filesystem.hpp"

class Texture {
public:
	Texture(const std::string& filename) : ID(load(filename)) {}
	Texture(const Texture&) = default;
	Texture(Texture&&) = default;
	virtual ~Texture() = default;

	uint32_t load(const std::string& filename);

private:
	uint32_t ID;
};

#endif