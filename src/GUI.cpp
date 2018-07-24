#include "GUI.hpp"

GUI::GUI(OpenGLWindow* screen): screen(screen), currentSelectedMesh(nullptr), dragging(false), selectedCycle(5) {}

GUI::~GUI() {}

void GUI::createCyclePanel() {

	nanogui::Window* guiWindow = new nanogui::Window(this->screen, "Cycles");
	guiWindow->setPosition(nanogui::Vector2i(20, 15));
	guiWindow->setLayout(new nanogui::GroupLayout());

	// Parent GUI Panel, vertical orientation
	parentPanel = new nanogui::Widget(guiWindow);
	parentPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 20));

	nanogui::Button *standingButton = new nanogui::Button(guiWindow, "Standing");
	nanogui::Button *walkingButton = new nanogui::Button(guiWindow, "Walking");
	nanogui::Button *jumpingButton = new nanogui::Button(guiWindow, "Jumping");
	nanogui::Button *moonWalshButton = new nanogui::Button(guiWindow, "MoonWalk");
	nanogui::Button *waveButton = new nanogui::Button(guiWindow, "Wave");
	nanogui::Button *pushUpButton = new nanogui::Button(guiWindow, "PushUp");
	standingButton->setCallback([this] { this->selectedCycle = 0; });
	walkingButton->setCallback([this] { this->selectedCycle = 1; });
	jumpingButton->setCallback([this] { this->selectedCycle = 2; });
	moonWalshButton->setCallback([this] { this->selectedCycle = 3; });
	waveButton->setCallback([this] { this->selectedCycle = 4; });
	pushUpButton->setCallback([this] { this->selectedCycle = 5; });

	sliderSpeed = new nanogui::Slider(guiWindow);
	sliderSpeed->setValue(16.0f / 100.0f);
	sliderSpeed->setFixedWidth(200);

	textBoxSpeed = new nanogui::TextBox(guiWindow);
	textBoxSpeed->setFixedSize(nanogui::Vector2i(200, 30));
	textBoxSpeed->setValue("16");
	textBoxSpeed->setUnits("speed");

	sliderSpeed->setCallback([this](float value) {
		textBoxSpeed->setValue(std::to_string((int) (value * 100)));
		Frame::setFrameLength((int)(value * 100));
	});
}

int GUI::getSelectedCycle() const { 
	return this->selectedCycle;
}

void GUI::createSettings() {

	nanogui::Window* guiWindow = new nanogui::Window(this->screen, "HumanGL Settings");
	guiWindow->setPosition(nanogui::Vector2i(20, 150));
	guiWindow->setLayout(new nanogui::GroupLayout());

	// Parent GUI Panel, vertical orientation
	parentPanel = new nanogui::Widget(guiWindow);
	parentPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 20));
	this->createScalePanels();

	nanogui::Button* b = new nanogui::Button(this->parentPanel, "Stop");

	this->createCyclePanel();
}

void GUI::createScalePanels() {
	// scale GUI Panel, vertical orientation
	scalePanel = new nanogui::Widget(parentPanel);
	scalePanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 20));
	new nanogui::Label(scalePanel, "scale", "sans-bold");

	// scale X GUI Panel, horizontal orientation
	// ========================================================
	nanogui::Widget* scaleXPanel = new nanogui::Widget(scalePanel);
	scaleXPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 20));
	new nanogui::Label(scaleXPanel, "X", "sans-bold");

	sliderX = new nanogui::Slider(scaleXPanel);
	sliderX->setValue(0.0f);
	sliderX->setFixedWidth(100);

	textBoxX = new nanogui::TextBox(scaleXPanel);
	textBoxX->setFixedSize(nanogui::Vector2i(60, 25));
	textBoxX->setValue("0");
	textBoxX->setUnits("°");

	sliderX->setCallback([this](float value) {
		textBoxX->setValue(std::to_string((int) (value * 360)));
		if (currentSelectedMesh) {

			Vector newScale = currentSelectedMesh->getScale();
			currentSelectedMesh->setScale(Vector(value * 360, newScale[1], newScale[2]));
		}
	});
	textBoxX->setFixedSize(nanogui::Vector2i(60,25));
	textBoxX->setFontSize(20);
	textBoxX->setAlignment(nanogui::TextBox::Alignment::Right);
	// ========================================================

	// scale Y GUI Panel, horizontal orientation
	scaleYPanel = new nanogui::Widget(scalePanel);
	scaleYPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 20));

	new nanogui::Label(scaleYPanel, "Y", "sans-bold");

	sliderY = new nanogui::Slider(scaleYPanel);
	sliderY->setValue(0.0f);
	sliderY->setFixedWidth(100);

	textBoxY = new nanogui::TextBox(scaleYPanel);
	textBoxY->setFixedSize(nanogui::Vector2i(60, 25));
	textBoxY->setValue("0");
	textBoxY->setUnits("°");

	sliderY->setCallback([this](float value) {
		textBoxY->setValue(std::to_string((int)(value * 360)));
		if (currentSelectedMesh) {
			Vector newScale = currentSelectedMesh->getScale();
			currentSelectedMesh->setScale(Vector(newScale[0], value * 360, newScale[2]));
		}
	});

	textBoxY->setFixedSize(nanogui::Vector2i(60, 30));
	textBoxY->setFontSize(20);
	textBoxY->setAlignment(nanogui::TextBox::Alignment::Right);

	// ========================================================

	// scale Z GUI Panel, horizontal orientation
	scaleZPanel = new nanogui::Widget(scalePanel);
	scaleZPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 20));

	new nanogui::Label(scaleZPanel, "Z", "sans-bold");

	sliderZ = new nanogui::Slider(scaleZPanel);
	sliderZ->setValue(0.0f);
	sliderZ->setFixedWidth(100);

	textBoxZ = new nanogui::TextBox(scaleZPanel);
	textBoxZ->setFixedSize(nanogui::Vector2i(60, 25));
	textBoxZ->setValue("0");
	textBoxZ->setUnits("°");


	sliderZ->setCallback([this](float value) {
		textBoxZ->setValue(std::to_string((int)(value * 360)));
		if (currentSelectedMesh) {
			Vector newScale = currentSelectedMesh->getScale();
			currentSelectedMesh->setScale(Vector(newScale[0], newScale[1], value * 360));
		}
	});

	textBoxZ->setFixedSize(nanogui::Vector2i(60, 30));
	textBoxZ->setFontSize(20);
	textBoxZ->setAlignment(nanogui::TextBox::Alignment::Right);
}

void GUI::setSelectedMesh(Mesh *selectedMesh) {
	if (selectedMesh) {
		this->currentSelectedMesh = selectedMesh;
		Vector scale = this->currentSelectedMesh->getScale();
		textBoxX->setValue(std::to_string((int)scale[0]));
		textBoxY->setValue(std::to_string((int)scale[1]));
		textBoxZ->setValue(std::to_string((int)scale[2]));

		sliderX->setValue(scale[0] / 360);
		sliderY->setValue(scale[1] / 360);
		sliderZ->setValue(scale[2] / 360);

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