#include"prop_dynamic.h"

prop_dynamic::prop_dynamic(DynamicTransform transform, const std::string& modelPath, const std::vector<std::string>& texturesPath)
	: transform(transform), model(modelPath, texturesPath) {}

void prop_dynamic::draw(Shader& shader) {
	glm::mat4 prop = glm::mat4(1.0f);

	prop = glm::translate(glm::mat4(1.0f), transform.position);
	prop = glm::rotate(prop, glm::radians(transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	prop = glm::rotate(prop, glm::radians(transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	prop = glm::rotate(prop, glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	prop = glm::scale(prop, transform.scale);

	shader.setMat4("model", prop);

	model.draw(shader);
}

void prop_dynamic::setPosition(glm::vec3 desiredPos)
{
	transform.position = desiredPos;
}

glm::vec3 prop_dynamic::getPosition() const
{
	return transform.position;
}

void prop_dynamic::setRotation(glm::vec3 desiredRot)
{
	transform.rotation = desiredRot;
}

glm::vec3 prop_dynamic::getRotation() const
{
	return transform.rotation;
}

void prop_dynamic::setScale(glm::vec3 desiredScale)
{
	transform.scale = desiredScale;
}

glm::vec3 prop_dynamic::getScale() const
{
	return transform.scale;
}