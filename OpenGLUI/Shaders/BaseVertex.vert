#version 330 core

layout(location = 0) in vec4 pos;
layout(location = 1) in vec2 textureCoordsIn;


out vec2 textureCoords;

void main()
{
    gl_Position = pos.xyzw;

    textureCoords = textureCoordsIn;
}
