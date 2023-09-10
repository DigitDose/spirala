#version 440 core

out vec4 FragColor;

void main()
{
    vec2 pos = gl_FragCoord.xy / vec2(1920.0, 1080.0);
    pos = 2.0 * pos - 1.0;
    pos *= vec2(10.0s, 10.0);

    float a = atan(pos.y, pos.x);
    float r = length(pos);
    float n = floor(r + a / (2.0 * 3.14159));
    float color = mod(n, 2.0);

    float x = mod(gl_FragCoord.x, 40.0);
    float y = mod(gl_FragCoord.y, 40.0);

    if ((x < 5.0 || x > 35.0) && (y < 5.0 || y > 35.0)) {
        color = 0.0; // Czarny
    } else {
        color = 1.0; // Biały
    }

    FragColor = vec4(vec3(color), 1.0);
}
