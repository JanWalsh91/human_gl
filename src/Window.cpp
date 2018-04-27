	#include "Window.hpp"

Window::Window( int width, int height, std::string const & title ) {
	if (!glfwInit()) {
		// exception
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	if (!(this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr))) {
		// exception
	}
	this->shaderProgram = Shader("src/Shaders/base.vert", "src/Shaders/base.frag");
	this->shaderProgram.use();
}

Window::Window( Window const & Window ) {
	*this = Window;
}

Window::~Window() {
	glfwTerminate();
}

void Window::loop(Cycle & cycle) {

	this->lastTimeFrame = glfwGetTime();
	while (1) {
		unsigned currentTime = glfwGetTime();

		glClearColor(0.f, 0.f, 0.f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (currentTime - this->lastTimeFrame > 16) {
			cycle.getCurrentFrame().getMeshes()[0].render();
			this->lastTimeFrame = currentTime;
		}



		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}


}

Window & Window::operator=( Window const & rhs ) {
	this->window = rhs.window;
	this->win_h = rhs.win_h;
	this->win_w = rhs.win_w;
	return *this;
}