#version 330 core

in vec4 fragmentColor;

out vec4 colorOut;

void main()
{
    colorOut = fragmentColor;
}