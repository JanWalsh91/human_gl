#version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aColor;

out vec3 ObjColor;
out vec2 TexCoord;

uniform vec3 shift;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int texture_application;

void main()
{
	gl_Position = projection * view * model * vec4(aPos - shift, 1.0);

	ObjColor = aColor;
	if (texture_application == 0)
		TexCoord = aTexCoord;
	else if (texture_application == 1)
		TexCoord = vec2(aPos.z, aPos.y);
	else if (texture_application == 2)
		TexCoord = vec2(aPos.x, aPos.y);
	else if (texture_application == 3)
		TexCoord = vec2(aPos.x, aPos.z);
}
