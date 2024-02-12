#version 330 core

in vec4 textureCoords;
uniform sampler2D unif_Texture;

out vec4 colorOut;


void main()
{
    colorOut = /*vec4(textureCoords.xy, 0.5, 1.0);*/texture(unif_Texture, textureCoords);
}