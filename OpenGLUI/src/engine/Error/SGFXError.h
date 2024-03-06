#include "SGFXEngine.h"

#if !defined(_SGFX_ERROR_H_)
#define _SGFX_ERROR_H_

#define GLCallErr(expression) expression; \
GlLogError();

#define GLCallErrDEBUG(expression, num) expression; \
GlLogErrorDEBUG(num);


void GlLogError();
void GlLogErrorDEBUG(int lineNum);

#endif