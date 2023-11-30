#version 330 core
out vec4 FragColor;

in vec3 outColor;
in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float mixValue;

void main() {
    //FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), mixValue);
    //FragColor = texture(texture1, texCoord);
    FragColor = vec4(outColor, 0);
    //if (gl_VertexID == 0) {
    //    FragColor = vec4(255, 0, 0, 0);
    //}
    //FragColor = vec3(255, 255, 255);
}
