#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include<GLFW/glfw3.h>
#include<glad/glad.h>
#include<iostream>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void update();
    bool shouldClose();
    GLFWwindow* getWindow();
    int getWidth();
    int getHeight();

private:
    GLFWwindow* window;
    int width;
    int height;
};

#endif // !WINDOW_CLASS_H
