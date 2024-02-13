#version 330 core

in vec2 textureCoords;
uniform sampler2D unif_Texture;

out vec4 colorOut;


void main()
{
    vec4 newColor = texture(unif_Texture, textureCoords);
    colorOut = newColor;
}