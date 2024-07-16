#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 1.5f;
const float SENSITIVITY = 0.1f;
const float FOV = 60.0f;

class Camera
{
	public:
		glm::vec3 Position;
		glm::vec3 Front;
		glm::vec3 Up;
		glm::vec3 Right;
		glm::vec3 WorldUp;

		float Yaw;
		float Pitch;

		float MovementSpeed;
		float MouseSensitivity;
		float Fov;

		Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) 
			: MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Fov(FOV) 
		{
			Position = position;
			WorldUp = up;
			Yaw = yaw;
			Pitch = pitch;
			updateCameraVectors();
		}

		glm::mat4 GetViewMatrix() {
			return glm::lookAt(Position, Position + Front, Up);
		}

		void ProcessKeyboard(Camera_Movement direction, float deltaTime) 
		{
			float velocity = MovementSpeed * deltaTime;
			switch (direction)
			{
			case FORWARD:
				Position += Front * velocity;
				break;
			case BACKWARD:
				Position -= Front * velocity;
				break;
			case LEFT:
				Position -= Right * velocity;
				break;
			case RIGHT:
				Position += Right * velocity;
				break;
			case UP:
				Position += WorldUp * velocity;
				break;
			case DOWN:
				Position -= WorldUp * velocity;
				break;
			}
		}

		void ProcessMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true) {
			xOffset *= MouseSensitivity;
			yOffset *= MouseSensitivity;

			Yaw += xOffset;
			Pitch += yOffset;

			if (constrainPitch)
			{
				if (Pitch > 89.0f)
					Pitch = 89.0f;
				if (Pitch < -89.0f)
					Pitch = -89.0f;
			}

			updateCameraVectors();
		}

		void ProcessMouseScroll(float yoffset)
		{
			MovementSpeed += (float)yoffset;
			if (MovementSpeed < 1.0f)
				MovementSpeed = 1.0f;
			if (MovementSpeed > 3.0f)
				MovementSpeed = 3.0f;
		}

	private:
		void updateCameraVectors() {
			glm::vec3 front;
			front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
			front.y = sin(glm::radians(Pitch));
			front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
			Front = glm::normalize(front);

			Right = glm::normalize(glm::cross(Front, WorldUp));
			Up = glm::normalize(glm::cross(Right, Front));
		}
};

#endif // !CAMERA_CLASS_H
