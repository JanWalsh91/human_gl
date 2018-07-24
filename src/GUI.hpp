#ifndef GUI_HPP
# define GUI_HPP

# include "OpenGLWindow.hpp"
# include "Frame.hpp"

class GUI {

public:
	GUI(OpenGLWindow* screen);
	~GUI();

	void createSettings();

	Vector const & getClickPosition() const;
	Vector const & getCurrentMeshScale() const;
	bool isDragging() const;
	bool needToUpdateFrames() const;
	Mesh* getSelectedMesh();

	void setSelectedMesh(Mesh* selectedMesh);
	void setClickPosition(Vector vector);
	void setDragging(bool dragging);
	void setUpdateFrames(bool b);

	int getSelectedCycle() const;

private:

	OpenGLWindow*	screen;
	Mesh*			currentSelectedMesh;

	Vector clickPosition;
	Vector currentMeshScale;
	bool	dragging;
	bool	updateFrames;

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
