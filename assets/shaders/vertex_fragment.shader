#shader vertex

#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec4 vColor;
out vec2 TexCoord;

void main()
{
    vColor = aColor;
    gl_Position = vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}



#shader fragment

#version 330 core

in vec4 vColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D uTexture;

void main()
{
    FragColor = texture(uTexture, TexCoord) * vColor;
}