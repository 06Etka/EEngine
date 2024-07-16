#include"Window.h"

Window::Window(int width, int height, const char* title)
    : width(width), height(height) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(this->width, this->height, title, NULL, NULL);
    if (window == NULL) {
        std::cerr << "FAILED TO CREATE GLFW WINDOW" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "FAILED TO INITIALIZE GLAD" << std::endl;
    }
}

Window::~Window() {
    glfwTerminate();
}

void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

GLFWwindow* Window::getWindow() {
    return window;
}

int Window::getWidth() {
    return width;
}
int Window::getHeight() {
    return height;
}