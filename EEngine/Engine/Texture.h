#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <string>

#include"stb_image.h"

struct TextureInfo
{
	unsigned int id;
	std::string type;
	std::string path;
};

class Texture 
{
	public:
		Texture(const std::string& filePath, const std::string& typeName);
		void bind(GLenum textureUnit = GL_TEXTURE0) const;
		void unbind() const;
		unsigned int getId() const { return textureInfo.id; }
		std::string getType() const { return textureInfo.type; }
		std::string getPath() const { return textureInfo.path; }

	private:
		TextureInfo textureInfo;
		void loadTexture(const std::string& filePath);
};

#endif // !TEXTURE_CLASS_H
