#ifndef PROP_STATIC_CLASS_H
#define PROP_STATIC_CLASS_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Model.h"
#include"Shader.h"

struct StaticTransform
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

class prop_static
{
	public:
		prop_static(StaticTransform transform, const std::string& modelPath, const std::vector<std::string>& texturesPath);

		void draw(Shader& shader);

		glm::vec3 getPosition() const;
		glm::vec3 getRotation() const;
		glm::vec3 getScale() const;

		Model model;
	private:
		StaticTransform transform;

};

#endif // !PROP_STATIC_CLASS_H
