#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include<glad/glad.h>
#include<glm/glm.hpp>

#include<vector>

#include"Shader.h"

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture
{
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh {
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void draw(Shader& shader);

private:
	unsigned int VAO, VBO, EBO;

	void setupMesh();
};

#endif // !MESH_CLASS_H
