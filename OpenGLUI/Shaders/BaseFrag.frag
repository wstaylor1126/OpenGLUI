#version 330 core

out vec4 colorOut;

in vec4 fragColor;

void main()
{
    colorOut = fragColor;
}