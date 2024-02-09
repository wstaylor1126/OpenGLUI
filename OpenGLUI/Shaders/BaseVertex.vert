#version 330 core

out vec4 fragColor;

layout(location = 0) in vec4 pos;
uniform vec4 baseColor;


void main()
{
    gl_Position = pos;
    fragColor = baseColor;
}
