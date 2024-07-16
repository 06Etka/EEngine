#include"directional_light.h"

directional_light::directional_light(DirectionalTransform transform, DirectionalLightProperties properties)
	: transform(transform), properties(properties) {}

void directional_light::setPosition(glm::vec3 desiredPos) 
{
	transform.position = desiredPos;
}

glm::vec3 directional_light::getPosition() const 
{
	return transform.position;
}

void directional_light::setRotation(glm::vec3 desiredRot) 
{
	transform.rotation = desiredRot;
}

glm::vec3 directional_light::getRotation() const 
{
	return transform.rotation;
}

void directional_light::setScale(glm::vec3 desiredScale)
{
	transform.scale = desiredScale;
}
glm::vec3 directional_light::getScale() const 
{
	return transform.scale;
}

void directional_light::setTargetPosition(glm::vec3 targetPos) {
	targetPosition = targetPos;
}

glm::vec3 directional_light::getDirection() const {
	return glm::normalize(targetPosition - transform.position);
}

glm::vec3 directional_light::getAmbient() const
{
	return properties.ambient;
}

glm::vec3 directional_light::getDiffuse() const 
{
	return properties.diffuse;
}

glm::vec3 directional_light::getSpecular() const 
{
	return properties.specular;
}