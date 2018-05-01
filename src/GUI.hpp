#ifndef GUI_HPP
#define GUI_HPP

#include "OpenGLWindow.hpp"

class GUI {

public:
	GUI(OpenGLWindow* screen);
	~GUI();

	void createSettings();
	void setSelectedMesh(Mesh* selectedMesh);

private:

	OpenGLWindow*	screen;
	Mesh*			currentSelectedMesh;


	nanogui::Widget* parentPanel;
	nanogui::Widget* rotationPanel;

	nanogui::Widget* rotationXPanel;
	nanogui::Slider *sliderX;
	nanogui::TextBox *textBoxX;

	nanogui::Widget* rotationYPanel;
	nanogui::Slider *sliderY;
	nanogui::TextBox *textBoxY;

	nanogui::Widget* rotationZPanel;
	nanogui::Slider *sliderZ;
	nanogui::TextBox *textBoxZ;
	void createRotationPanels();

};


#endif
