#include "texture.hpp"

uint32_t Texture::load(const std::string& filename) {
	int width, height, num_channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(
		filename.c_str(),
		&width,
		&height,
		&num_channels,
		0);

	uint32_t texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);
		return texture;
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
		return -1;
	}
}