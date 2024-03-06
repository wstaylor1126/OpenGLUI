#if !defined(_SGFX_RENDERER_H_)
#define _SGFX_RENDERER_H_

#include "SGFXEngine.h"
#include "Renderer/Shader.h"
#include "Vertex/VertexArray.h"
#include "Vertex/IndexBuffer.h"
#include "Vertex/VertexBuffer.h"

constexpr unsigned int vertexCount = 6;
constexpr unsigned int vertexAttribCount = 4;
inline unsigned int textureLocation;

//--This whole file right now is temporary bullshit. So is it's .cpp definition file

namespace renderer
{
	//--Temporary bullshit
	inline unsigned int indexBuffer[vertexCount] =
	{
		0, 1, 3,
		1, 2, 3,
	};
	inline float vertexPositions[vertexAttribCount * 4] =
	{
		-0.25f, -0.75f, 0.0f, 1.0f,
		0.25f, -0.75f, 0.0f, 1.0f,
		0.25f, 0.75f, 0.0f, 1.0f,
		-0.25f, 0.75f, 0.0f, 1.0f,
	};
	inline float textureCoords[vertexAttribCount * 2] =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
	};
}

void sgfxDraw(const ShaderProgram& shader, const VertexArray& vertexArray, const IndexBuf& indexBuffer, const VertexAttribBufLayout& vertexAttributes);

#endif