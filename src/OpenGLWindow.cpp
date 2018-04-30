#include "OpenGLWindow.hpp"

#include "Mesh/TorsoMesh.hpp"
#include "Mesh/ArmMesh.hpp"
#include "Mesh/HeadMesh.hpp"

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



	this->createWidget();

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

void OpenGLWindow::createWidget() {
	nanogui::Window* guiWindow = new nanogui::Window(this, "HumanGL Settings");
	guiWindow->setPosition(nanogui::Vector2i(20, 15));
	guiWindow->setLayout(new nanogui::GroupLayout());

//	new nanogui::Label(guiWindow, "Message dialog", "sans-bold");
//	nanogui::Widget *tools = new nanogui::Widget(guiWindow);
//	tools->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal,
//											nanogui::Alignment::Middle, 0, 6));
//	nanogui::Button *b = new nanogui::Button(tools, "Info");
//	b->setCallback([&] {
//		auto dlg = new nanogui::MessageDialog(this, nanogui::MessageDialog::Type::Information, "Title", "This is an information message");
//		dlg->setCallback([](int result) { std::cout << "Dialog result: " << result << std::endl; });
//	});
//	b = new nanogui::Button(tools, "Warn");
//	b->setCallback([&] {
//		auto dlg = new nanogui::MessageDialog(this, nanogui::MessageDialog::Type::Warning, "Title", "This is a warning message");
//		dlg->setCallback([](int result) { std::cout << "Dialog result: " << result << std::endl; });
//	});
//	b = new nanogui::Button(tools, "Ask");
//	b->setCallback([&] {
//		auto dlg = new nanogui::MessageDialog(this, nanogui::MessageDialog::Type::Warning, "Title", "This is a question message", "Yes", "No", true);
//		dlg->setCallback([](int result) { std::cout << "Dialog result: " << result << std::endl; });
//	});
//
//	new nanogui::Label(guiWindow, "Image panel & scroll panel", "sans-bold");
//	nanogui::PopupButton *imagePanelBtn = new nanogui::PopupButton(guiWindow, "Image Panel");
//	imagePanelBtn->setIcon(ENTYPO_ICON_FOLDER);
//
//	new nanogui::Label(guiWindow, "File dialog", "sans-bold");
//	tools = new Widget(guiWindow);
//	tools->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal,
//											nanogui::Alignment::Middle, 0, 6));
//	b = new nanogui::Button(tools, "Open");
//	b->setCallback([&] {
//
//	});
//	b = new nanogui::Button(tools, "Save");
//	b->setCallback([&] {
//
//	});
//
//	new nanogui::Label(guiWindow, "Combo box", "sans-bold");
//	new nanogui::ComboBox(guiWindow, { "Combo box item 1", "Combo box item 2", "Combo box item 3"});
//	new nanogui::Label(guiWindow, "Check box", "sans-bold");
//	nanogui::CheckBox *cb = new nanogui::CheckBox(guiWindow, "Flag 1",
//								[](bool state) { std::cout << "Check box 1 state: " << state << std::endl; }
//	);
//	cb->setChecked(true);
//	cb = new nanogui::CheckBox(guiWindow, "Flag 2",
//					  [](bool state) { std::cout << "Check box 2 state: " << state << std::endl; }
//	);
//	new nanogui::Label(guiWindow, "Progress bar", "sans-bold");
//	nanogui::ProgressBar* mProgress = new nanogui::ProgressBar(guiWindow);

	new nanogui::Label(guiWindow, "Rotation", "sans-bold");

	nanogui::Widget *panel = new Widget(guiWindow);
	panel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 20));

	new nanogui::Label(panel, "X", "sans-bold");

	nanogui::Slider *slider = new nanogui::Slider(panel);
	slider->setValue(0.5f);
	slider->setFixedWidth(100);

	nanogui::TextBox *textBox = new nanogui::TextBox(panel);
	textBox->setFixedSize(nanogui::Vector2i(60, 25));
	textBox->setValue("100");
	textBox->setUnits("%");


	slider->setCallback([this, textBox](float value) {
		textBox->setValue(std::to_string((int) (value * 100)));
		std::cout << value << std::endl;
		// this->human->setRotationSpeedX(value);
		this->poubelle = value;
	});
	slider->setFinalCallback([&](float value) {
		std::cout << "Final slider value: " << (int) (value * 100) << std::endl;
		
	});
	textBox->setFixedSize(nanogui::Vector2i(60,25));
	textBox->setFontSize(20);
	textBox->setAlignment(nanogui::TextBox::Alignment::Right);
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

#include <unistd.h>

void OpenGLWindow::loop(Cycle & cycle) {
//	this->lastTimeFrame = glfwGetTime();


//	Mesh mesh(Vector(0, 180, 0), Vector(1, 2, 1), Vector(0, 0, 0), Vector(1, 0, 1));
//	Mesh mesh2(Vector(0, 0, 0), Vector(0.2, 0.5, 0.2), Vector(0.7, 0, 0), Vector(0, 1, 0));
//	Mesh mesh3(Vector(0, 0, 0), Vector(0.2, 0.5, 0.2), Vector(-0.7, 0, 0), Vector(0, 0.5, 0));

	TorsoMesh torso;
	ArmMesh		rightArm(Side::RIGHT, Vector(0, 0, 0));
	ArmMesh		leftArm(Side::LEFT, Vector(0, 0, 0));
	HeadMesh	head(Vector(0, 0, 0));
	Mesh		leftSubArm(
		Vector(30, 0, 0), // rotationAngles
		Vector(0, 0, 0), // rotation origin 
		Vector(0.25, 0.5, 0.25), //scale 
		Vector(0, 0, 0), // scale origin
		Vector(0, -1.5, -0.3), // translate
		Vector(0, 0, 1), // color
		"RightSUBArm");

	this->poubelle = 0;
	torso.append(&rightArm);
	torso.append(&leftArm);
	torso.append(&head);
	rightArm.append(&leftSubArm);
	Matrix i;
	Vector o;
	torso.recursivelyUpdateMatrices(i, o);
	// exit(0);
	while (!glfwWindowShouldClose(this->window) && glfwGetKey(this->window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glEnable(GL_DEPTH_TEST);
//		double currentTime = glfwGetTime();
		glfwPollEvents();

		// torso.setRotationAngles(Vector(torso.rotationAngles[0], glfwGetTime() * (this->human->getRotationSpeed()[0] * 100), torso.rotationAngles[2]));
		// torso.setRotationAngles(Vector(glfwGetTime() * (this->human->getRotationSpeed()[0] * 100), glfwGetTime() * (this->human->getRotationSpeed()[0] * 100), glfwGetTime() * (this->human->getRotationSpeed()[0] * 100)));
		rightArm.setRotationAngles(Vector( glfwGetTime() * (this->human->getRotationSpeed()[0] * 100), rightArm.rotationAngles[1], rightArm.rotationAngles[2] ));
		// torso.setRotationAngles(Vector(torso.rotationAngles[0], torso.rotationAngles[1], this->poubelle * 360));
		
		torso.recursivelyUpdateMatrices(i, o);

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