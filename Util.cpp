/*
* OpenGL(GLEW) Utils and Simplifications
* Simplified by KrowFeather
* latest update: 2023/3/5
*/
#include<iostream>
#include<fstream>
#include<string>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include "Util.h"
using namespace std;

string Util::readShaderSource(const char* filePath)
{
	string content;
	ifstream fileStream(filePath, ios::in);
	string line = "";
	while (!fileStream.eof())
	{
		getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}

void Util::printShaderLog(GLuint shader)
{
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, &chWrittn, log);
		cout << "Shader Info Log: " << log << endl;
		free(log);
	}
}

void Util::printProgramLog(int prog)
{
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		cout << "Program Info Log: " << log << endl;
		free(log);
	}
}

bool Util::checkOpenGLError()
{
	bool foundError = false;
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		cout << "GLError:" << glErr << endl;
		foundError = true;
		glErr = glGetError();
	}
	return foundError;
}

GLuint Util::createShaderProgram(const char* vp, const char* fp)
{
	string vshaderSourceSrc = Util::readShaderSource(vp);
	string fshaderSourceSrc = Util::readShaderSource(fp);

	const char* vshaderSource = vshaderSourceSrc.c_str();
	const char* fshaderSource = fshaderSourceSrc.c_str();

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShader, 1, &vshaderSource, NULL);
	glShaderSource(fShader, 1, &fshaderSource, NULL);
	glCompileShader(vShader);
	glCompileShader(fShader);
	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	glLinkProgram(vfProgram);
	return vfProgram;
}

void Util::checkGLFW()
{
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
}

void Util::checkGLEW()
{
	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}
}

void Util::versionControl()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
}

void Util::endProg(GLFWwindow* window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
