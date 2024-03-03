#if !defined(_SGFX_ERROR_H_)
#define _SGFX_ERROR_H_

#include "SGFXEngine.h"

#define GLCallErr(expression) expression; \
GlLogError();

#define GLCallErrDEBUG(expression, num) expression; \
GlLogErrorDEBUG(num);


void GlLogError();
void GlLogErrorDEBUG(int lineNum);

#endif