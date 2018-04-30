#include "OpenGLWindow.hpp"

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

	this->human->initCycles();

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


void OpenGLWindow::loop() {
//	this->lastTimeFrame = glfwGetTime();


//	Mesh mesh(Vector(0, 180, 0), Vector(1, 2, 1), Vector(0, 0, 0), Vector(1, 0, 1));
//	Mesh mesh2(Vector(0, 0, 0), Vector(0.2, 0.5, 0.2), Vector(0.7, 0, 0), Vector(0, 1, 0));
//	Mesh mesh3(Vector(0, 0, 0), Vector(0.2, 0.5, 0.2), Vector(-0.7, 0, 0), Vector(0, 0.5, 0));

	// TorsoMesh torso;
	// ArmMesh		rightArm(Side::RIGHT, Vector(-3, 0, 4));
	// ArmMesh		leftArm(Side::LEFT, Vector(-3, 0, -4));
	// LowerArmMesh		lowerRightArm(Side::RIGHT, Vector(4, 0, -4));
	// LowerArmMesh		lowerLeftArm(Side::LEFT, Vector(4, 0, 4));
	// LowerLegMesh		lowerRightLeg(Side::RIGHT, Vector(-10, 0, 0));
	// LowerLegMesh		lowerLeftLeg(Side::LEFT, Vector(-10, 0, 0));
	// LegMesh		rightLeg(Side::RIGHT, Vector(5, 0, 0));
	// LegMesh		leftLeg(Side::LEFT, Vector(5, 0, 0));
	// HandMesh		rightHand(Side::RIGHT, Vector(0, 0, 0));
	// HandMesh		leftHand(Side::LEFT, Vector(0, 0, 0));
	// FootMesh		rightFoot(Side::RIGHT, Vector(0, 0, 0));
	// FootMesh		leftFoot(Side::LEFT, Vector(0, 0, 0));
	// HeadMesh	head(Vector(0, 0, 0));

	this->poubelle = 0;
	// torso.append(&rightArm);
	// torso.append(&leftArm);
	// torso.append(&rightLeg);
	// torso.append(&leftLeg);
	// leftLeg.append(&lowerLeftLeg);
	// rightLeg.append(&lowerRightLeg);
	// torso.append(&head);
	// rightArm.append(&lowerRightArm);
	// leftArm.append(&lowerLeftArm);
	// lowerRightArm.append(&rightHand);
	// lowerLeftArm.append(&leftHand);
	// lowerRightLeg.append(&rightFoot);
	// lowerLeftLeg.append(&leftFoot);
	Matrix i;
	Vector o;
	// torso.recursivelyUpdateMatrices(i, o);
	// exit(0);
	while (!glfwWindowShouldClose(this->window) && glfwGetKey(this->window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glEnable(GL_DEPTH_TEST);
//		double currentTime = glfwGetTime();
		glfwPollEvents();

		// torso.setRotationAngles(Vector(torso.rotationAngles[0], glfwGetTime() * (this->human->getRotationSpeed()[0] * 100), torso.rotationAngles[2]));
		// torso.setRotationAngles(Vector(glfwGetTime() * (this->human->getRotationSpeed()[0] * 100), glfwGetTime() * (this->human->getRotationSpeed()[0] * 100), glfwGetTime() * (this->human->getRotationSpeed()[0] * 100)));
		// rightArm.setRotationAngles(Vector( std::sin(glfwGetTime()) * 50, rightArm.rotationAngles[1], rightArm.rotationAngles[2] ));
		// leftArm.setRotationAngles(Vector( -std::sin(glfwGetTime()) * 50, leftArm.rotationAngles[1], leftArm.rotationAngles[2] ));
		// lowerLeftArm.setRotationAngles(Vector( std::cos(glfwGetTime()) * 50, lowerLeftArm.rotationAngles[1], lowerLeftArm.rotationAngles[2] ));
		// lowerRightArm.setRotationAngles(Vector( -std::cos(glfwGetTime()) * 50, lowerRightArm.rotationAngles[1], lowerRightArm.rotationAngles[2] ));
		// torso.setRotationAngles(Vector(torso.rotationAngles[0], torso.rotationAngles[1], this->poubelle * 360));
		// head.setRotationAngles(Vector(-std::cos(glfwGetTime() * 10) * 20, 0, 0));
		// leftLeg.setRotationAngles(Vector( std::sin(glfwGetTime()) * 20, 0, 0));
		// rightLeg.setRotationAngles(Vector( -std::sin(glfwGetTime()) * 20, 0, 0));

		// lowerLeftLeg.setRotationAngles(Vector( 0, 0, std::sin(glfwGetTime() * 5) * 90));
		// lowerRightLeg.setRotationAngles(Vector( 0, 0, -std::sin(glfwGetTime() * 5) * 90));

		// torso.recursivelyUpdateMatrices(i, o);

		// std::cout << "Poubelle: " << this->poubelle << std::endl;

		// this->human->cycles[0].keyFrames[0]->getRoot()->recursivelyUpdateMatrices(i, o);

		
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

		// this->human->cycles[0].keyFrames[0]->getRoot()->recursivelyRender(this->shaderProgram);

		// torso.recursivelyRender(this->shaderProgram);
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