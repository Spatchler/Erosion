#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec3 outColor;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    //outColor = vec3(model * vec4(aPos, 1.0));
    //outColor = aPos;
    // Colors
    vec3 white  = vec3(255, 255, 255);
    vec3 yellow = vec3(255, 255, 0);
    vec3 green  = vec3(0, 255, 0);
    vec3 blue   = vec3(0, 0, 255);
    vec3 red    = vec3(255, 0, 0);
    vec3 orange = vec3(255, 127, 0);
    //x
    if ((model * vec4(aPos, 1.0)).x > 2) {
        outColor = orange;
    }
    else if ((model * vec4(aPos, 1.0)).x < 0) {
        outColor = red;
    }
    //y
    if ((model * vec4(aPos, 1.0)).y > 2) {
        outColor = white;
    }
    else if ((model * vec4(aPos, 1.0)).y < 0) {
        outColor = yellow;
    }
    //z
    if ((model * vec4(aPos, 1.0)).z > 2) {
        outColor = blue;
    }
    else if ((model * vec4(aPos, 1.0)).z < 0) {
        outColor = green;
    }

    texCoord = aTexCoord;
}
