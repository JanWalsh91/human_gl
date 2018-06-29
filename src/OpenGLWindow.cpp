#include "OpenGLWindow.hpp"
#include "ExceptionMsg.hpp"


OpenGLWindow::OpenGLWindow( int width, int height, std::string const & title ): nanogui::Screen(), width(width), height(height) {
	if (!(this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr))) {
		throw ExceptionMsg("Failed to create window");
	}
	glfwMakeContextCurrent(this->window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw ExceptionMsg("Failed to initialize GLAD");
	}
	this->shaderProgram = Shader("../src/Shaders/base.vert", "../src/Shaders/base.frag");
	this->shaderProgram.use();
	this->human = new HumanGL();

	this->human->initCycles();

//	this->camPos = Vector(0, 0, -10);
//	this->camRight = Vector(1, 0, 0);
//	this->camUp = Vector(0, 1, 0);
//	this->camDir = Vector(0, 0, 1);
//	this->viewMatrix = Matrix(this->camPos * -1 , Matrix::TYPE::TRANSLATE);
//	this->viewMatrix[0] = this->camRight[0];
//	this->viewMatrix[1] = this->camRight[1];
//	this->viewMatrix[2] = this->camRight[2];
//	this->viewMatrix[4] = this->camUp[0];
//	this->viewMatrix[5] = this->camUp[1];
//	this->viewMatrix[6] = this->camUp[2];
//	this->viewMatrix[8] = this->camDir[0];
//	this->viewMatrix[9] = this->camDir[1];
//	this->viewMatrix[10] = this->camDir[2];

	this->PMatrix = Matrix(100.0f, 0.1f, (float)this->width / (float)this->height, 45, Matrix::TYPE::PROJECTION);


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

//		double xposOri, yposOri;
//		glfwGetCursorPos(screen->window, &xposOri, &yposOri);
//		screen->gui->setClickPosition(Vector(xposOri, yposOri, 0));
//
//		if (screen->gui->isDragging()) {
//
//			double xpos, ypos;
//			glfwGetCursorPos(screen->window, &xpos, &ypos);
//			std::cout << "Drag distance: " << screen->gui->getClickPosition()[0] - xpos << ", " << screen->gui->getClickPosition()[1] - ypos << std::endl;
//			Vector dir = screen->camera.getCameraDirection();
//
//			dir[0] = dir[0] + (screen->gui->getClickPosition()[0] - xpos) / 100000;
//			std::cout << dir << std::endl;
//			dir.normalize();
//
//			screen->camera.setCameraDirection(dir);
//			screen->shaderProgram.setMatrix("viewMatrix",  screen->camera.getViewMatrix());
//		}

		 }
	);

	glfwSetMouseButtonCallback(window, [](GLFWwindow *win, int button, int action, int modifiers) {
			OpenGLWindow* screen = (OpenGLWindow*)glfwGetWindowUserPointer(win);
			screen->mouseButtonCallbackEvent(button, action, modifiers);
			if (button == GLFW_MOUSE_BUTTON_LEFT) {
				if(GLFW_PRESS == action) {
					screen->gui->setDragging(true);
				}
				else if(GLFW_RELEASE == action) {
					screen->gui->setDragging(false);
				}
			}
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
		throw ExceptionMsg("Failed to initialize GLFW");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

//void OpenGLWindow::drawContents() {
//
//}


void OpenGLWindow::loop() {

	this->poubelle = 0;
	Matrix i;
	Vector o;

	this->shaderProgram.setMatrix("viewMatrix",  this->camera.getViewMatrix());
	this->shaderProgram.setMatrix("projectionMatrix",  this->PMatrix);
	while (!glfwWindowShouldClose(this->window) && glfwGetKey(this->window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glfwPollEvents();

		glClearColor(0.2f, 0.2f, .5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Frame currentFrame = this->human->getCycles()[0]->getCurrentFrame();
		currentFrame.getRoot()->recursivelyUpdateMatrices(i, o);

		this->drawWidgets();
		glEnable(GL_DEPTH_TEST);
		this->drawContents();
		this->shaderProgram.use();

		glBindVertexArray(human->getVAO());
		glBindBuffer(GL_ARRAY_BUFFER, human->getVBO());

		currentFrame.getRoot()->recursivelyRender(this->shaderProgram);


		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT)) {
			glFlush();
			glFinish();
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			float data[4];
			data[0] = 0;
			data[1] = 0;
			data[2] = 0;
			data[3] = 0;
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);
			ypos = this->height - ypos;
			glReadPixels(xpos, ypos, 1, 1, GL_RGB, GL_FLOAT, data);
			//this->human->cycles[0]->keyFrames[0]->getHead()->setColor(Vector((float)data[0], (float)data[1], (float)data[2]));
			Mesh* tmp = currentFrame.getRoot()->getByColor(Vector((float)data[0], (float)data[1], (float)data[2]));
			if (tmp)
				std::cout << "========= tmp: " << tmp->getName() << std::endl;

			this->gui->setSelectedMesh(tmp);

			//unsigned char res[4];
			//GLint viewport[4];
			//glGetIntegerv(GL_VIEWPORT, viewport);
			//glReadPixels(xpos, ypos, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &res);		
		}
		glfwSwapBuffers(this->window);
	}


}

OpenGLWindow & OpenGLWindow::operator=( OpenGLWindow const & rhs ) {
	this->window = rhs.window;
	this->width = rhs.width;
	this->height = rhs.height;
	return *this;
}