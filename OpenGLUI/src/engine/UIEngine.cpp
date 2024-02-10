#include "UIEngine.h"


//--Callbacks
void UIEngine::glfwErrorCallback(int errCode, const char* description)
{
	std::cout << "GLFW error: " << errCode << ": " << description << std::endl;
}
void UIEngine::glfwKeyCallback(GLFWwindow* window, int keyCode, int scanCode, int action, int mods)
{
	UIEngine* engine = (UIEngine*)glfwGetWindowUserPointer(window);

	
	if (keyCode >= 48 && keyCode <=57 && action == GLFW_PRESS)
	{
		uiengine::vertexId = keyCode - 48;
	}
}
void UIEngine::glfwCursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
{
	UIEngine* engine = (UIEngine*)glfwGetWindowUserPointer(window);
	if (xPos != 0 && yPos != 0)
	{
		engine->_cursorPosX_ = xPos;
		engine->_cursorPosY_ = yPos;
	}
}
void UIEngine::glfwMouseButtonCallback(GLFWwindow* window, int buttonCode, int action, int mods)
{
	UIEngine* engine = (UIEngine*)glfwGetWindowUserPointer(window);

	if (buttonCode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		uiengine::cursorIsHeld = 1;
	}
	else if (buttonCode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		uiengine::cursorIsHeld = 0;
	}
}
void UIEngine::glfwFrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	UIEngine* engine = (UIEngine*)glfwGetWindowUserPointer(window);
	Draw(engine->window);
	engine->_windowX_ = width;
	engine->_windowY_ = height;
	glViewport(0, 0, width, height);
}
void UIEngine::glfwWindowPosCallback(GLFWwindow* window, int xpos, int ypos)
{
	UIEngine* engine = (UIEngine*)glfwGetWindowUserPointer(window);
	Draw(engine->window);
}

//--Public
UIEngine::UIEngine()
{

}
UIEngine::~UIEngine()
{

	glfwTerminate();
}
int UIEngine::Init(int windowX, int windowY, const char* title, GLFWmonitor* monitor)
{
	if (!glfwInit())
	{
		std::cout << "GLFW initialization failed." << std::endl;
		return 0;
	}

	window = glfwCreateWindow(windowX, windowY, title, monitor, nullptr);
	glfwMakeContextCurrent(window);

	BindWindowToEngineContext();

	_windowX_ = windowX;
	_windowY_ = windowY;

	GLenum errCode = glewInit();

	if (errCode)
	{
		const char* glewErrStr = (char*)glewGetErrorString(errCode);
		std::cout << "GLEW error: " << glewErrStr << std::endl;
		return 0;
	}

	SetGLFWCallbacks();

	return 1;
}
//--Private
void UIEngine::SetGLFWCallbacks()
{
	glfwSetErrorCallback((GLFWerrorfun)glfwErrorCallback);
	glfwSetKeyCallback(window, (GLFWkeyfun)glfwKeyCallback);
	glfwSetCursorPosCallback(window, (GLFWcursorposfun)glfwCursorPositionCallback);
	glfwSetMouseButtonCallback(window, (GLFWmousebuttonfun)glfwMouseButtonCallback);
	glfwSetFramebufferSizeCallback(window, (GLFWframebuffersizefun)glfwFrameBufferSizeCallback);
	glfwSetWindowPosCallback(window, (GLFWwindowposfun)glfwWindowPosCallback);
}
void UIEngine::BindWindowToEngineContext()
{
	glfwSetWindowUserPointer(window, this);
}



