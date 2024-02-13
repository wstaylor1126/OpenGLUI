#include "SGFXEngine.h"


//--Callbacks
void SGFXEngine::glfwErrorCallback(int errCode, const char* description)
{
	std::cout << "GLFW error: " << errCode << ": " << description << std::endl;
}
void SGFXEngine::glfwKeyCallback(GLFWwindow* window, int keyCode, int scanCode, int action, int mods)
{
	SGFXEngine* engine = (SGFXEngine*)glfwGetWindowUserPointer(window);

	
	if (keyCode >= 48 && keyCode <=57 && action == GLFW_PRESS)
	{
		sgfxengine::vertexId = keyCode - 48;
	}
}
void SGFXEngine::glfwCursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
{
	SGFXEngine* engine = (SGFXEngine*)glfwGetWindowUserPointer(window);
	if (xPos != 0 && yPos != 0)
	{
		engine->_cursorPosX_ = xPos;
		engine->_cursorPosY_ = yPos;
	}
}
void SGFXEngine::glfwMouseButtonCallback(GLFWwindow* window, int buttonCode, int action, int mods)
{
	SGFXEngine* engine = (SGFXEngine*)glfwGetWindowUserPointer(window);

	if (buttonCode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		sgfxengine::cursorIsHeld = 1;
	}
	else if (buttonCode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		sgfxengine::cursorIsHeld = 0;
	}
}
void SGFXEngine::glfwFrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	SGFXEngine* engine = (SGFXEngine*)glfwGetWindowUserPointer(window);
	engine->_windowX_ = width;
	engine->_windowY_ = height;
	glViewport(0, 0, width, height);

	Draw(engine->window);
}
void SGFXEngine::glfwWindowPosCallback(GLFWwindow* window, int xpos, int ypos)
{
	SGFXEngine* engine = (SGFXEngine*)glfwGetWindowUserPointer(window);

	Draw(engine->window);
}


//--Public
SGFXEngine::SGFXEngine()
{

}
SGFXEngine::~SGFXEngine()
{
	glfwTerminate();
}
int SGFXEngine::Init(int windowX, int windowY, const char* title, GLFWmonitor* monitor)
{
	if (!glfwInit())
	{
		std::cout << "GLFW initialization failed." << std::endl;
		return 0;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _GL_MAJOR_VERSION_);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _GL_MINOR_VERSION_);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	

	window = glfwCreateWindow(windowX, windowY, title, monitor, nullptr);
	glfwMakeContextCurrent(window);

#ifdef _SHOW_GL_CONTEXT_INFO_
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
#endif

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
void SGFXEngine::SetGLFWCallbacks()
{
	glfwSetErrorCallback((GLFWerrorfun)glfwErrorCallback);
	glfwSetKeyCallback(window, (GLFWkeyfun)glfwKeyCallback);
	glfwSetCursorPosCallback(window, (GLFWcursorposfun)glfwCursorPositionCallback);
	glfwSetMouseButtonCallback(window, (GLFWmousebuttonfun)glfwMouseButtonCallback);
	glfwSetFramebufferSizeCallback(window, (GLFWframebuffersizefun)glfwFrameBufferSizeCallback);
	glfwSetWindowPosCallback(window, (GLFWwindowposfun)glfwWindowPosCallback);
}
void SGFXEngine::BindWindowToEngineContext()
{
	glfwSetWindowUserPointer(window, this);
}



