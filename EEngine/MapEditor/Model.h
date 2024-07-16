#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include<vector>

#include"Shader.h"
#include"Mesh.h"
#include"stb_image.h"

class Model
{
public:
	Model(std::string path);
	void draw(Shader& shader);

	bool isLoaded() const;
	void setPosition(const glm::vec3& position);
	glm::vec3 getPosition();

private:
	std::vector<Mesh> meshes;
	std::vector<Texture> textures_loaded;
	std::string directory;

	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char* path, const std::string& directory);

	glm::vec3 position;
};

#endif // !MODEL_CLASS_H
