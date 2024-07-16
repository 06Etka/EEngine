#ifndef DIRECTIONAL_LIGHT_CLASS_H
#define DIRECTIONAL_LIGHT_CLASS_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

struct DirectionalTransform
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

struct DirectionalLightProperties
{
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};

class directional_light 
{
	public:
		directional_light(DirectionalTransform transform, DirectionalLightProperties properties);
		
		void setPosition(glm::vec3 desiredPos);
		glm::vec3 getPosition() const;
		void setRotation(glm::vec3 desiredRot);
		glm::vec3 getRotation() const;
		void setScale(glm::vec3 desiredScale);
		glm::vec3 getScale() const;

		void setTargetPosition(glm::vec3 targetPos);
		glm::vec3 getDirection() const;
		glm::vec3 getAmbient() const;
		glm::vec3 getDiffuse() const;
		glm::vec3 getSpecular() const;

	private:
		DirectionalTransform transform;
		DirectionalLightProperties properties;
		glm::vec3 targetPosition;
		
};

#endif // !DIRECTIONAL_LIGHT_CLASS_H
