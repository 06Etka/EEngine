#ifndef PROP_DYNAMIC_CLASS_H
#define PROP_DYNAMIC_CLASS_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Model.h"
#include"Shader.h"

struct DynamicTransform
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

class prop_dynamic
{
public:
	prop_dynamic(DynamicTransform transform, const std::string& modelPath, const std::vector<std::string>& texturesPath);

	void draw(Shader& shader);

	void setPosition(glm::vec3 desiredPos);
	glm::vec3 getPosition() const;
	void setRotation(glm::vec3 desiredRot);
	glm::vec3 getRotation() const;
	void setScale(glm::vec3 desiredScale);
	glm::vec3 getScale() const;

private:
	Model model;
	DynamicTransform transform;

};

#endif // !PROP_DYNAMIC_CLASS_H
