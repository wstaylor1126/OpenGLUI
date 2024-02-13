#version 330 core

layout(location = 0) in vec4 pos;
layout(location = 1) in vec2 textureCoordsIn;


out vec2 textureCoords;

void main()
{
    vec4 newPosition = vec4(pos.xyzw);
    gl_Position = newPosition;

    textureCoords = textureCoordsIn;
}
