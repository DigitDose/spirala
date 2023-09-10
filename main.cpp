#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "spirala.h"

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1920, 1080, "Spirala", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Inicjalizacja nie powiodła się" << std::endl;
        return -1;
    }

    const GLubyte* version = glGetString(GL_SHADING_LANGUAGE_VERSION);
    if (version)
    {
        std::cout << "Wersja GLSL: " << version << std::endl;
    }
    else
    {
        std::cout << "Nie można uzyskać informacji o wersji GLSL" << std::endl;
    }

    std::string vertexShaderSource = LoadShader("shaders/vertexShader.vert");
    std::string fragmentShaderSource = LoadShader("shaders/fragmentShader.frag");
    unsigned int shaderProgram = CreateShader(vertexShaderSource, fragmentShaderSource);

    GLint timeLocation = glGetUniformLocation(shaderProgram, "time");

    float vertices[] = {
        -1.0f, -1.0f,
         1.0f, -1.0f,
        -1.0f,  1.0f,
         1.0f,  1.0f,
    };

    unsigned int VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glUseProgram(shaderProgram);

        float currentTime = glfwGetTime();
        glUniform1f(timeLocation, currentTime);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
