#ifndef _GAME_HPP
#define _GAME_HPP

#include "state.hpp"
#include "motor/graphics/image.hpp"
#include "motor/graphics/shader.hpp"
#include "motor/graphics/camera.hpp"
//#include "motor/utility/log.hpp"
#include "motor/utility/time.hpp"
#include "motor/utility/settings.hpp"
#include "motor/io/input.hpp"
#include "motor/math/aabb.hpp"

#include <motor/math/glm/glm.hpp>
#include <motor/math/glm/gtc/matrix_transform.hpp>
#include <motor/math/glm/gtx/projection.hpp>
#include <motor/math/glm/gtc/type_ptr.hpp>

using glm::vec3;

#include <cmath>
#include <iostream>
#include <ostream>
using namespace std;

namespace motor
{
	struct vertex_t
	{
		vertex_t() {}
		vertex_t(glm::vec3 pos, glm::vec4 col) : position(pos), color(col) {}
		glm::vec3 position;
		glm::vec4 color;
	};

	class Game : public State
	{
		public:
			Game();
			int main(Window*, Input*, Time*);
			void init();
			void load();
			void unload();
			void update();
			void draw();
			~Game();

		private:
			Input *input;
			Window *window;
			Time *time;
			Camera *camera;
			Settings *settings;

			Shader *baseShader;

			bool loop;
	};
}
#endif
