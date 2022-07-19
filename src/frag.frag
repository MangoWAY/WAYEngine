#version 330 core
out vec4 FragColor;

in vec4 vertexColor; // 从顶点着色器传来的输入变量（名称相同、类型相同）
in vec2 texcoord;
uniform vec4 color;
uniform sampler2D van;
uniform sampler2D l;
void main()
{
    FragColor = mix(texture(van, texcoord), texture(l, texcoord), 0.5);
}