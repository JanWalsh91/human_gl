#include "OpenGLWindow.hpp"

#include "Mesh/TorsoMesh.hpp"
#include "Mesh/ArmMesh.hpp"

OpenGLWindow::OpenGLWindow( int width, int height, std::string const & title ): nanogui::Screen(), width(width), height(height) {
	if (!(this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr))) {
		// exception
	}
	glfwMakeContextCurrent(this->window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		// exception
	}
	this->shaderProgram = Shader("../src/Shaders/base.vert", "../src/Shaders/base.frag");
	this->shaderProgram.use();
	std::cout << "init window" << std::endl;
	this->human = new HumanGL();
	this->camPos = Vector(0, 0, -10);
	this->camRight = Vector(1, 0, 0);
	this->camUp = Vector(0, 1, 0);
	this->camDir = Vector(0, 0, 1);
	this->viewMatrix = Matrix(this->camPos * -1 , Matrix::TYPE::TRANSLATE);
	this->viewMatrix[0] = this->camRight[0];
	this->viewMatrix[1] = this->camRight[1];
	this->viewMatrix[2] = this->camRight[2];
	this->viewMatrix[4] = this->camUp[0];
	this->viewMatrix[5] = this->camUp[1];
	this->viewMatrix[6] = this->camUp[2];
	this->viewMatrix[8] = this->camDir[0];
	this->viewMatrix[9] = this->camDir[1];
	this->viewMatrix[10] = this->camDir[2];
	// std::cout << "View Matrix: \n" << this->viewMatrix << std::endl;
	this->PMatrix = Matrix(100, 0.1, (float)this->width / (float)this->height, 45, Matrix::TYPE::PROJECTION);
	this->initialize(this->window, true);


	int w, h;
	glfwGetFramebufferSize(window, &w, &h);
	glViewport(0, 0, w, h);
	glfwSwapInterval(0);
	glfwSwapBuffers(window);



	bool enabled = true;

	this->gui = new GUI(this);
	this->gui->createSettings();

	this->setVisible(true);
	this->performLayout();

	glfwSetWindowUserPointer(this->window, this);

	glfwSetCursorPosCallback(window, [](GLFWwindow *win, double x, double y) {
		OpenGLWindow* screen = (OpenGLWindow*)glfwGetWindowUserPointer(win);
			 screen->cursorPosCallbackEvent(x, y);
		 }
	);

	glfwSetMouseButtonCallback(window, [](GLFWwindow *win, int button, int action, int modifiers) {
		OpenGLWindow* screen = (OpenGLWindow*)glfwGetWindowUserPointer(win);
			screen->mouseButtonCallbackEvent(button, action, modifiers);
		}
	);

	glfwSetKeyCallback(window, [](GLFWwindow *win, int key, int scancode, int action, int mods) {
		OpenGLWindow* screen = (OpenGLWindow*)glfwGetWindowUserPointer(win);
   			screen->keyCallbackEvent(key, scancode, action, mods);
	   }
	);

	glfwSetCharCallback(window, [](GLFWwindow *win, unsigned int codepoint) {
		OpenGLWindow* screen = (OpenGLWindow*)glfwGetWindowUserPointer(win);
			screen->charCallbackEvent(codepoint);
		}
	);

	glfwSetDropCallback(window, [](GLFWwindow *win, int count, const char **filenames) {
		OpenGLWindow* screen = (OpenGLWindow*)glfwGetWindowUserPointer(win);
			screen->dropCallbackEvent(count, filenames);
		}
	);

	glfwSetScrollCallback(window, [](GLFWwindow *win, double x, double y) {
		OpenGLWindow* screen = (OpenGLWindow*)glfwGetWindowUserPointer(win);
			screen->scrollCallbackEvent(x, y);
		}
	);

	glfwSetFramebufferSizeCallback(window, [](GLFWwindow *win, int width, int height) {
		OpenGLWindow* screen = (OpenGLWindow*)glfwGetWindowUserPointer(win);
			screen->resizeCallbackEvent(width, height);
	   }
	);
}

OpenGLWindow::OpenGLWindow( OpenGLWindow const & Window ) {
	*this = Window;
}

OpenGLWindow::~OpenGLWindow() {
	glfwTerminate();
	delete this->human;
}

void OpenGLWindow::initOpenGL() {
	if (!glfwInit()) {
		// exception
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

//void OpenGLWindow::drawContents() {
//
//}


void OpenGLWindow::loop(Cycle & cycle) {
//	this->lastTimeFrame = glfwGetTime();


//	Mesh mesh(Vector(0, 180, 0), Vector(1, 2, 1), Vector(0, 0, 0), Vector(1, 0, 1));
//	Mesh mesh2(Vector(0, 0, 0), Vector(0.2, 0.5, 0.2), Vector(0.7, 0, 0), Vector(0, 1, 0));
//	Mesh mesh3(Vector(0, 0, 0), Vector(0.2, 0.5, 0.2), Vector(-0.7, 0, 0), Vector(0, 0.5, 0));

	TorsoMesh torso;
	ArmMesh		rightArm(Side::RIGHT, Vector(0, 0, 0));
	// ArmMesh		leftArm(Side::LEFT, Vector(80, 0, 0));
	Mesh		leftSubArm(
		Vector(0, 0, 0),
		Vector(0, 0, 0),
		Vector(0.5, 0.5, 0.5),
		Vector(0.5, 0.5, 0.5),
		Vector(0, -1, 0),
		Vector(0, 0, 1),
		"RightSUBArm");

	this->poubelle = 0;
	torso.append(&rightArm);
	rightArm.append(&leftSubArm);
	// torso.append(leftArm);
	Matrix i;
	torso.recursivelyUpdateModelMatrix(i);
	// exit(0);
	while (!glfwWindowShouldClose(this->window) && glfwGetKey(this->window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glEnable(GL_DEPTH_TEST);
//		double currentTime = glfwGetTime();
		glfwPollEvents();

		torso.setRotationAngles(Vector(0, 60+0 *(this->human->getRotationSpeed()[0] * 360), 0));
		rightArm.setRotationAngles(Vector(this->poubelle * 360, 0, 0));
		torso.recursivelyUpdateModelMatrix(i);

		std::cout << "Poubelle: " << this->poubelle << std::endl;

		glClearColor(0.2f, 0.2f, .5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		this->drawContents();
//		if (currentTime - this->lastTimeFrame > 16) {
//			cycle.getCurrentFrame().getMeshes()[0].render();
//			this->lastTimeFrame = currentTime;
//		}

//		this->shaderProgram.setVector("color", Vector(1, 0.5, 0));
		this->shaderProgram.setMatrix("viewMatrix",  this->viewMatrix);
		this->shaderProgram.setMatrix("projectionMatrix",  this->PMatrix);
//
		this->shaderProgram.use();
		// for (int i = 0; i < 6; i++) {

		// }


		glBindVertexArray(human->getVAO());
		glBindBuffer(GL_ARRAY_BUFFER, human->getVBO());

		torso.recursivelyRender(this->shaderProgram);
		// exit(0);

//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);

		this->drawWidgets();

		glfwSwapBuffers(this->window);

	}


}

OpenGLWindow & OpenGLWindow::operator=( OpenGLWindow const & rhs ) {
	this->window = rhs.window;
	this->width = rhs.width;
	this->height = rhs.height;
	return *this;
}