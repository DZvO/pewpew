#include "game.hpp"

motor::Game::Game()
{
	loop = true;
}

glm::vec2 rotate(glm::vec2 point, float angleDeg)
{
	float angle = angleDeg / 180.f * M_PI; //convert from degrees (0-360) to radians (0-2*PI)
	glm::vec2 rotPoint;
	rotPoint.x = point.x * cos(angle) - point.y * sin(angle);
	rotPoint.y = point.x * sin(angle) + point.y * cos(angle);
	return rotPoint;
}

ostream& operator<<(ostream& out, const glm::vec3& v)
{
	return out << "v3(" << v.x << "|" << v.y << "|" << v.z << ")";
}

ostream& operator<<(ostream& out, const motor::AABB& bb)
{
	return out << "AABB(" << bb.min << " - " << bb.max << ")";
}

int motor::Game::main(Window *wndw, Input *inp, Time *tt)
{
	window = wndw;
	input = inp;
	time = tt;

	cout << endl;

	baseShader = new motor::Shader();
	baseShader->init();

	baseShader->attachVertexShader("data/base.vert");
	baseShader->attachFragmentShader("data/base.frag");
	baseShader->compile();

	int positionAttrib;
	int colorAttrib;
	positionAttrib = baseShader->getAttributeLocation("position");
	colorAttrib = baseShader->getAttributeLocation("color");
	baseShader->activate();

	camera = new Camera(input, baseShader);
	//camera->setPerspective(45.0f, float(window->width) / float(window->height), window->near, window->far);
	camera->setOrtho(0, window->width, window->height, 0, window->near, window->far);
	camera->position = glm::vec3(0, 0, 0);

	cout << endl;

	//	glPolygonMode(GL_FRONT, GL_LINE);
	//
	//

	unsigned int vertBuffer = 0;
	glGenBuffers(1, &vertBuffer);

	vertex_t *vertices;
	vertices = new vertex_t[3];
	vertices[0] = vertex_t(vec3(0, 0, -1), glm::vec4(0.5, 0.0, 0.0, 1.0));
	//														-
	vertices[1] = vertex_t(vec3(0, 1, -1), glm::vec4(0.5, 0.0, 0.0, 1.0));
	vertices[2] = vertex_t(vec3(1, 0, -1), glm::vec4(0.5, 0.0, 0.0, 1.0));

	unsigned int vertexCount = 3;
	glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
	GLsizeiptr const vertSize = vertexCount * sizeof(vertex_t);
	glBufferData(GL_ARRAY_BUFFER, vertSize, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	while(loop)
	{
		time->update();
		input->update(time, window);//, time);


		if(input->quit())
			loop = false;
		if(input->windowResized())
		{
			cout << "handled!" << window->width << " " << window->height << endl;
			camera->setPerspective(45.0f, float(window->width) / float(window->height), 0.3f, window->far); 
		}

		if(input->isPressed(Key::LEFT))
			camera->position.x -= .1f;
		if(input->isPressed(Key::RIGHT))
			camera->position.x += .1f;

		camera->think();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnableVertexAttribArray(positionAttrib);
		glEnableVertexAttribArray(colorAttrib);

#define _OFFSET(i) ((char *)NULL + (i))
		glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
		glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), _OFFSET(0));
		glVertexAttribPointer(colorAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_t), _OFFSET(sizeof(glm::vec3)));
		glDrawArrays(GL_TRIANGLES, 0, vertexCount);

		SDL_GL_SwapBuffers();
	}
	return 0;
}
void motor::Game::update()
{
}

void motor::Game::draw()
{
}

void motor::Game::init()
{
}

void motor::Game::load()
{
}

void motor::Game::unload()
{
}

motor::Game::~Game()
{
	cout << endl << "bye" << endl;
}
