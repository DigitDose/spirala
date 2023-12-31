#version 440 core

layout (location = 0) in vec3 aPos; // Wierzchołek wejściowy

// Zmienne wyjściowe do fragment shadera
out vec4 vertexColor;
 
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); // Ustalamy pozycję wierzchołka
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // Przykładowy kolor
}
