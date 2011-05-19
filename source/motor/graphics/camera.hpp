#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#include <iostream>
using namespace std;

#include <GL/glew.h>
#include <GL/gl.h>

#include "motor/io/input.hpp"
#include "motor/graphics/shader.hpp"

#include <motor/math/glm/glm.hpp>
#include <motor/math/glm/gtc/matrix_transform.hpp>
#include <motor/math/glm/gtx/projection.hpp>
#include <motor/math/glm/gtc/type_ptr.hpp>

namespace motor
{
	class Camera
	{
		public:
			Camera(Input *inputPtr, Shader *shaderPtr);
			void setPerspective(float fov, float aspectRatio, float near, float far);
			void setOrtho(float left, float right, float bottom, float top, float near, float far);

			//void moveLoc(float x, float y, float z, float distance);
			//void moveGlo(float x, float y, float z, float distance);
			//void rotateLoc(float x, float y, float z, float degrees);
			//void rotateGlo(float x, float y, float z, float degrees);

			void movePosition(glm::vec3 delta);
			void moveRotation(glm::vec3 delta);

			void setPosition(glm::vec3 pos);
			void setRotation(glm::vec3 rot);

			void think();

			glm::vec3 position;
			glm::vec3 rotation;
		private:
			Input *input;
			Shader *shader;

			glm::vec3 lookAt;
			glm::mat4 projectionMatrix;
			glm::mat4 viewMatrix;
			glm::mat4 modelMatrix;

			int projectionMatrixUniform;
			int viewMatrixUniform;
			int modelMatrixUniform;
	};
}
#endif
