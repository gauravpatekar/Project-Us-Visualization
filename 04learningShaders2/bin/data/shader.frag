#version 150

out vec4 outputColor;

uniform float u_red;

void main(){
    float red = u_red;
    float green = 0.6;
    float blue = 0.6;
    float alpha = 1.0;
    outputColor = vec4(red, green, blue, alpha);
}
