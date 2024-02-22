#include "SGFXEngine.h"


//--Callbacks
void SGFXEngine::glfwErrorCallback(int errCode, const char* description)
{
	std::cout << "GLFW error: " << errCode << ": " << description << std::endl;
}
void SGFXEngine::glfwKeyCallback(GLFWwindow* window, int keyCode, int scanCode, int action, int mods)
{
	SGFXEngine* engine = (SGFXEngine*)glfwGetWindowUserPointer(window);

	if (keyCode >= 48 && keyCode <= 57 && action == GLFW_PRESS)
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
	//--This probably needs a proper definition. Will most likely just be a wrapper for the Init() function
}
SGFXEngine::~SGFXEngine()
{
	glfwTerminate();
}
int SGFXEngine::Init(int windowX, int windowY, const char* title, GLFWmonitor* monitor)
{
	//--Most of the basic initialization is done. Will almost certainly be expanded upon in the future
	if (!glfwInit())
	{
		std::cout << "GLFW initialization failed." << std::endl;
		return 0;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _GL_MAJOR_VERSION_);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _GL_MINOR_VERSION_);

#if defined(_GL_USING_CORE_PROFILE_)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

	window = glfwCreateWindow(windowX, windowY, title, monitor, nullptr);
	glfwMakeContextCurrent(window);

#if defined(_SHOW_GL_CONTEXT_INFO_)
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
#endif

	BindWindowToEngineContext();

	//--This will probably be offloaded or won't be stored in the SGFXEngine class itself, not sure yet
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



