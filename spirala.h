#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

unsigned int CompileShader(unsigned int type, const std::string& source);
std::string LoadShader(const std::string& filename);
unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
