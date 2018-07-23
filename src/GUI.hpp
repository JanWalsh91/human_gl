#ifndef GUI_HPP
#define GUI_HPP

#include "OpenGLWindow.hpp"
#include "Frame.hpp"

class GUI {

public:
	GUI(OpenGLWindow* screen);
	~GUI();

	void createSettings();

	Vector const & getClickPosition() const;
	bool isDragging() const;

	void setSelectedMesh(Mesh* selectedMesh);
	void setClickPosition(Vector vector);
	void setDragging(bool dragging);

	int getSelectedCycle() const;

private:

	OpenGLWindow*	screen;
	Mesh*			currentSelectedMesh;

	Vector clickPosition;
	bool	dragging;

	nanogui::Widget* parentPanel;
	nanogui::Widget* scalePanel;

	nanogui::Widget* scaleXPanel;
	nanogui::Slider *sliderX;
	nanogui::TextBox *textBoxX;

	nanogui::Widget* scaleYPanel;
	nanogui::Slider *sliderY;
	nanogui::TextBox *textBoxY;

	nanogui::Widget* scaleZPanel;
	nanogui::Slider *sliderZ;
	nanogui::TextBox *textBoxZ;

	nanogui::Widget* scaleSpeedPanel;
	nanogui::Slider *sliderSpeed;
	nanogui::TextBox *textBoxSpeed;

	void createScalePanels();
	void createCyclePanel();

	int selectedCycle;
};


#endif
