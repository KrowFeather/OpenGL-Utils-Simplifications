/*
* OpenGL(GLEW) Utils and Simplifications
* Simplified by KrowFeather
* latest update: 2023/3/5
*/
#pragma once
#include<string>
#include<GLFW/glfw3.h>
#include<GL/glew.h>
#include<iostream>
using namespace std;
#define EXITSUCCESS exit(EXIT_SUCCESS)
#define EXITFAILURE exit(EXIT_FAILURE)
#define SwapBuffers(x) glfwSwapBuffers(x)
#define CloseWindow(x) glfwWindowShouldClose(x)
#define PollEvents(x) glfwPollEvents(x)
#define SwapInterval(x) glfwSwapInterval(x)
#define CreateWindow glfwCreateWindow
#define MCC(x) glfwMakeContextCurrent(x)
#define Cube1x {-1.0f,1.0f,-1.0f,-1.0f,-1.0f,-1.0f,1.0f,-1.0f,-1.0f,1.0f,-1.0f,-1.0f,1.0f,1.0f,-1.0f,-1.0f,1.0f,-1.0f,1.0f,-1.0f,-1.0f,1.0f,-1.0f,1.0f,1.0f,1.0f,-1.0f,1.0f,-1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,-1.0f,1.0f,-1.0f,1.0f,-1.0f,-1.0f,1.0f,1.0f,1.0f,1.0f,-1.0f,-1.0f,1.0f,-1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,-1.0f,-1.0f,1.0f,-1.0f,-1.0f,-1.0f,-1.0f,1.0f,1.0f,-1.0f,-1.0f,-1.0f,-1.0f,1.0f,-1.0f,-1.0f,1.0f,1.0f,-1.0f,-1.0f,1.0f,1.0f,-1.0f,1.0f,1.0f,-1.0f,1.0f,-1.0f,1.0f,-1.0f,1.0f,1.0f,-1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,-1.0f,1.0f,1.0f,-1.0f,1.0f,-1.0f}
class Util
{
public:
	static string readShaderSource(const char* filePath);
	static void printShaderLog(GLuint shader);
	static void printProgramLog(int prog);
	static bool checkOpenGLError();
	static GLuint createShaderProgram(const char *vp,const char *fp);
	static void checkGLFW();
	static void checkGLEW();
	static void versionControl();
	static void endProg(GLFWwindow* window);
};

