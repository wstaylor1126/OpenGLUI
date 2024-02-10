#version 330 core

layout(location = 0) in vec4 pos;
layout(location = 1) in vec4 color;

out vec4 fragmentColor;

void main()
{
    gl_Position = pos;
    fragmentColor = color;
}
