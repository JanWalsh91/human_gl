#include "GUI.hpp"

GUI::GUI(OpenGLWindow* screen): screen(screen) {}

GUI::~GUI() {}

void GUI::createSettings() {

	nanogui::Window* guiWindow = new nanogui::Window(this->screen, "HumanGL Settings");
	guiWindow->setPosition(nanogui::Vector2i(20, 15));
	guiWindow->setLayout(new nanogui::GroupLayout());

	new nanogui::Label(guiWindow, "Rotation", "sans-bold");

	nanogui::Widget *panel = new nanogui::Widget(guiWindow);
	panel->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 20));

	new nanogui::Label(panel, "X", "sans-bold");

	nanogui::Slider *slider = new nanogui::Slider(panel);
	slider->setValue(1.0f);
	slider->setFixedWidth(100);

	nanogui::TextBox *textBox = new nanogui::TextBox(panel);
	textBox->setFixedSize(nanogui::Vector2i(60, 25));
	textBox->setValue("100");
	textBox->setUnits("%");


	slider->setCallback([this, textBox](float value) {
		textBox->setValue(std::to_string((int) (value * 100)));
		std::cout << value << std::endl;

	});
	slider->setFinalCallback([&](float value) {
		std::cout << "Final slider value: " << (int) (value * 100) << std::endl;
		this->screen->getHuman()->setRotationSpeedX(value);
	});
	textBox->setFixedSize(nanogui::Vector2i(60,25));
	textBox->setFontSize(20);
	textBox->setAlignment(nanogui::TextBox::Alignment::Right);

}