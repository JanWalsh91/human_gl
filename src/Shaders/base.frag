#version 410 core

out vec4 FragColor;

in vec3 ObjColor;
in vec2 TexCoord;

uniform sampler2D tex;
uniform float ratio;

void main()
{
	FragColor = mix(texture(tex, TexCoord), vec4(ObjColor, 1.0), ratio);
}