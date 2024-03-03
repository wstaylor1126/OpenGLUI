#include "SGFXError.h"

void GlLogError()
{
	GLenum err;
	while (err = glGetError())
	{
		std::cout << "[OpenGl Error]: " << std::hex << err << std::dec << std::endl;
	}
}
void GlLogErrorDEBUG(int lineNum)
{
	GLenum err;
	while (err = glGetError())
	{
		std::cout << "(" << lineNum << ")" << "[OpenGl Error]: " << std::hex << err << std::dec << std::endl;
	}
}