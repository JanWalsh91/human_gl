#include "GUI.hpp"

GUI::GUI(OpenGLWindow* screen): screen(screen), currentSelectedMesh(nullptr), dragging(false) {}

GUI::~GUI() {}

void GUI::createSettings() {

	nanogui::Window* guiWindow = new nanogui::Window(this->screen, "HumanGL Settings");
	guiWindow->setPosition(nanogui::Vector2i(20, 15));
	guiWindow->setLayout(new nanogui::GroupLayout());

	// Parent GUI Panel, vertical orientation
	parentPanel = new nanogui::Widget(guiWindow);
	parentPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 20));
	this->createRotationPanels();

	nanogui::Button* b = new nanogui::Button(this->parentPanel, "Stop");
}

void GUI::createRotationPanels() {
	// Rotation GUI Panel, vertical orientation
	rotationPanel = new nanogui::Widget(parentPanel);
	rotationPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 20));
	new nanogui::Label(rotationPanel, "Rotation", "sans-bold");

	// Rotation X GUI Panel, horizontal orientation
	// ========================================================
	nanogui::Widget* rotationXPanel = new nanogui::Widget(rotationPanel);
	rotationXPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 20));
	new nanogui::Label(rotationXPanel, "X", "sans-bold");

	sliderX = new nanogui::Slider(rotationXPanel);
	sliderX->setValue(0.0f);
	sliderX->setFixedWidth(100);

	textBoxX = new nanogui::TextBox(rotationXPanel);
	textBoxX->setFixedSize(nanogui::Vector2i(60, 25));
	textBoxX->setValue("0");
	textBoxX->setUnits("°");

	sliderX->setCallback([this](float value) {
		textBoxX->setValue(std::to_string((int) (value * 360)));
		if (currentSelectedMesh) {

			Vector newAngles = currentSelectedMesh->getRotationAngles();
			currentSelectedMesh->setRotationAngles(Vector(value * 360, newAngles[1], newAngles[2]));
		}
	});
	textBoxX->setFixedSize(nanogui::Vector2i(60,25));
	textBoxX->setFontSize(20);
	textBoxX->setAlignment(nanogui::TextBox::Alignment::Right);
	// ========================================================

	// Rotation Y GUI Panel, horizontal orientation
	rotationYPanel = new nanogui::Widget(rotationPanel);
	rotationYPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 20));

	new nanogui::Label(rotationYPanel, "Y", "sans-bold");

	sliderY = new nanogui::Slider(rotationYPanel);
	sliderY->setValue(0.0f);
	sliderY->setFixedWidth(100);

	textBoxY = new nanogui::TextBox(rotationYPanel);
	textBoxY->setFixedSize(nanogui::Vector2i(60, 25));
	textBoxY->setValue("0");
	textBoxY->setUnits("°");

	sliderY->setCallback([this](float value) {
		textBoxY->setValue(std::to_string((int)(value * 360)));
		if (currentSelectedMesh) {
			Vector newAngles = currentSelectedMesh->getRotationAngles();
			currentSelectedMesh->setRotationAngles(Vector(newAngles[0], value * 360, newAngles[2]));
		}
	});

	textBoxY->setFixedSize(nanogui::Vector2i(60, 30));
	textBoxY->setFontSize(20);
	textBoxY->setAlignment(nanogui::TextBox::Alignment::Right);

	// ========================================================

	// Rotation Z GUI Panel, horizontal orientation
	rotationZPanel = new nanogui::Widget(rotationPanel);
	rotationZPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 20));

	new nanogui::Label(rotationZPanel, "Z", "sans-bold");

	sliderZ = new nanogui::Slider(rotationZPanel);
	sliderZ->setValue(0.0f);
	sliderZ->setFixedWidth(100);

	textBoxZ = new nanogui::TextBox(rotationZPanel);
	textBoxZ->setFixedSize(nanogui::Vector2i(60, 25));
	textBoxZ->setValue("0");
	textBoxZ->setUnits("°");


	sliderZ->setCallback([this](float value) {
		textBoxZ->setValue(std::to_string((int)(value * 360)));
		if (currentSelectedMesh) {
			Vector newAngles = currentSelectedMesh->getRotationAngles();
			currentSelectedMesh->setRotationAngles(Vector(newAngles[0], newAngles[1], value * 360));
		}
	});

	textBoxZ->setFixedSize(nanogui::Vector2i(60, 30));
	textBoxZ->setFontSize(20);
	textBoxZ->setAlignment(nanogui::TextBox::Alignment::Right);
}

void GUI::setSelectedMesh(Mesh *selectedMesh) {
	if (selectedMesh) {
		this->currentSelectedMesh = selectedMesh;
		Vector rotationAngles = this->currentSelectedMesh->getRotationAngles();
		textBoxX->setValue(std::to_string((int)rotationAngles[0]));
		textBoxY->setValue(std::to_string((int)rotationAngles[1]));
		textBoxZ->setValue(std::to_string((int)rotationAngles[2]));

		sliderX->setValue(rotationAngles[0] / 360);
		sliderY->setValue(rotationAngles[1] / 360);
		sliderZ->setValue(rotationAngles[2] / 360);

		std::cout << "New Selection: " << selectedMesh->getName() << std::endl;
	}
}

void GUI::setClickPosition(Vector clickPosition) {
	this->clickPosition = clickPosition;
}

Vector const & GUI::getClickPosition() const {
	return this->clickPosition;
}

bool GUI::isDragging() const {
	return this->dragging;
}

void GUI::setDragging(bool dragging) {
	this->dragging = dragging;
}