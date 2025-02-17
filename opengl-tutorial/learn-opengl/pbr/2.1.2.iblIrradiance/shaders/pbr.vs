#version 330 core

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 vTexCoord;

out vec2 texCoord;
out vec3 worldPosition;
out vec3 normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main(){
    texCoord = vTexCoord;
    worldPosition = vec3(model * vec4(vPosition, 1.0));
    normal = mat3(model) * vNormal;

    gl_Position = projection * view * vec4(worldPosition, 1.0);
}