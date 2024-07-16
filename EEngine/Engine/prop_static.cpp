#include"prop_static.h"

prop_static::prop_static(StaticTransform transform, const std::string& modelPath, const std::vector<std::string>& texturesPath)
	: transform(transform), model(modelPath, texturesPath) {}

void prop_static::draw(Shader& shader) {
	glm::mat4 prop = glm::mat4(1.0f);

	prop = glm::translate(glm::mat4(1.0f), transform.position);
	prop = glm::rotate(prop, glm::radians(transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	prop = glm::rotate(prop, glm::radians(transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	prop = glm::rotate(prop, glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	prop = glm::scale(prop, transform.scale);

	shader.setMat4("model", prop);

	model.draw(shader);
}

glm::vec3 prop_static::getPosition() const 
{ 
	return transform.position; 
}

glm::vec3 prop_static::getRotation() const 
{ 
	return transform.rotation; 
}

glm::vec3 prop_static::getScale() const 
{ 
	return transform.scale; 
}