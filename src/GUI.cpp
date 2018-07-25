#include "GUI.hpp"

#include <iomanip>

GUI::GUI(OpenGLWindow* screen): screen(screen), currentSelectedMesh(nullptr), dragging(false), updateFrames(false), selectedCycle(0) {}

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
	guiWindow->setPosition(nanogui::Vector2i(20, 380));
	guiWindow->setLayout(new nanogui::GroupLayout());

	// Parent GUI Panel, vertical orientation
	parentPanel = new nanogui::Widget(guiWindow);
	parentPanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 20));
	this->createScalePanels();

	this->createCyclePanel();
}

void GUI::createScalePanels() {
	// scale GUI Panel, vertical orientation
	scalePanel = new nanogui::Widget(parentPanel);
	scalePanel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 20));
	new nanogui::Label(scalePanel, "Scale", "sans-bold");

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

	sliderX->setCallback([this](float value) {
		std::ostringstream out;
    	out << std::setprecision(2) << value * 5.0;
		textBoxX->setValue(out.str());
		if (currentSelectedMesh) {
			this->currentMeshScale = currentSelectedMesh->getScale();
			this->currentMeshScale = Vector(value * 3, this->currentMeshScale[1], this->currentMeshScale[2]);
			this->updateFrames = true;
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

	sliderY->setCallback([this](float value) {
		std::ostringstream out;
    	out << std::setprecision(2) << value * 5.0;
		textBoxY->setValue(out.str());
		if (currentSelectedMesh) {
			this->currentMeshScale = currentSelectedMesh->getScale();
			this->currentMeshScale = Vector(this->currentMeshScale[0], value * 3, this->currentMeshScale[2]);
			this->updateFrames = true;
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


	sliderZ->setCallback([this](float value) {
		std::ostringstream out;
    	out << std::setprecision(2) << value * 5.0;
		textBoxZ->setValue(out.str());
		if (currentSelectedMesh) {
			this->currentMeshScale = currentSelectedMesh->getScale();
			this->currentMeshScale = Vector(this->currentMeshScale[0], this->currentMeshScale[1], value * 3);
			this->updateFrames = true;
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

		std::ostringstream out;
    	out << std::setprecision(2) << scale[0];
		textBoxX->setValue(out.str());
		out.str("");
		out << std::setprecision(2) << scale[1];
		textBoxY->setValue(out.str());
		out.str("");
		out << std::setprecision(2) << scale[2];
		textBoxZ->setValue(out.str());

		std::cout << scale << std::endl;

		sliderX->setValue(scale[0] / 5.0f);
		sliderY->setValue(scale[1] / 5.0f);
		sliderZ->setValue(scale[2] / 5.0f);
	}
}

void GUI::setClickPosition(Vector clickPosition) {
	this->clickPosition = clickPosition;
}

Vector const & GUI::getClickPosition() const {
	return this->clickPosition;
}

Vector const & GUI::getCurrentMeshScale() const {
	return this->currentMeshScale;
}

bool GUI::isDragging() const {
	return this->dragging;
}

bool GUI::needToUpdateFrames() const {
	return this->updateFrames;
}

void GUI::setUpdateFrames(bool updateFrames) {
	this->updateFrames = updateFrames; 
}

void GUI::setDragging(bool dragging) {
	this->dragging = dragging;
}

Mesh* GUI::getSelectedMesh() {
	return this->currentSelectedMesh;
}
