#if !defined(_SGFX_INDEX_BUFFER_H_)
#define _SGFX_INDEX_BUFFER_H_

#include "SGFXEngine.h"

class IndexBuf
{
public:
	IndexBuf(const void* indexData, unsigned int count);
	~IndexBuf();
	void Bind() const;
	void Unbind() const;
	void DeleteGLBuf();

	unsigned int indexBufId, amount;
private:
};

#endif