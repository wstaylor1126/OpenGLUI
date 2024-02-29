#include "SGFXError.h"

void GlLogError()
{
	GLenum err;
	while (err = glGetError())
	{
		std::cout << "[OpenGl Error]: " << std::hex << err << std::endl;
	}
}