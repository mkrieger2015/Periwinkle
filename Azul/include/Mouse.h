#ifndef MOUSE_H
#define MOUSE_H

#include "Azul.h"


// Wrapper to buffer users from the internal glfw driver
// Converted to enumeration for type safety - yeah!

enum AZUL_MOUSE
{
	BUTTON_1        = 0,
	BUTTON_2        = 1,
	BUTTON_3        = 2,
	BUTTON_4        = 3,
	BUTTON_5        = 4,
	BUTTON_6        = 5,
	BUTTON_7        = 6,
	BUTTON_8        = 7,
	BUTTON_LEFT     = GLFW_MOUSE_BUTTON_1,
	BUTTON_RIGHT    = GLFW_MOUSE_BUTTON_2,
	BUTTON_MIDDLE   = GLFW_MOUSE_BUTTON_3
};

class Mouse
{
public:	
	Mouse(GLFWwindow *window);

	// Use this to read mouse buttons
	bool GetKeyState( AZUL_MOUSE button);

	// get cursor
	void GetCursor( float &xPos, float &yPos );
	//double xpos;
	//double ypos;

	// get mouse position
	//glfwGetCursorPos( window, &xpos, &ypos);

private:
	Mouse();  // for prevention
	GLFWwindow	*window;
};


#endif