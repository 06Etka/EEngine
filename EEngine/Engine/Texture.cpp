#include"Texture.h"

Texture::Texture(const std::string& filePath, const std::string& typeName) 
{
	textureInfo.type = typeName;
	loadTexture(filePath);
}

void Texture::loadTexture(const std::string& filepPath) 
{
	glGenTextures(1, &textureInfo.id);
	glBindTexture(GL_TEXTURE_2D, textureInfo.id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filepPath.c_str(), &width, &height, &nrChannels, 0);
	if (data) {
		GLenum format;

		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "FAILED TO LOAD TEXTURE AT: " << filepPath << std::endl;
	}
	stbi_image_free(data);
}

void Texture::bind(GLenum textureUnit) const {
	glActiveTexture(textureUnit);
	glBindTexture(GL_TEXTURE_2D, textureInfo.id);
}

void Texture::unbind() const{
	glBindTexture(GL_TEXTURE_2D, 0);
}