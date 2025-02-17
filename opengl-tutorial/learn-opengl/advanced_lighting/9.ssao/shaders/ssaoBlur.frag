#version 330 core

out float fragColor;

in vec2 texCoord;

uniform sampler2D ssaoInput;

void main(){
    vec2 texSize = 1.0 / vec2(textureSize(ssaoInput, 0));
    float result = 0.0;

    for(int x = -2; x < 2; x++) {
        for (int y = -2; y < 2; y++) {
            vec2 offset = vec2(float(x), float (y)) * texSize;
            result += texture(ssaoInput, texCoord + offset).r;
        }
    }

    fragColor = result / (4.0 * 4.0);
}