#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Renderer/Renderer.h"
#include "Window.h"



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  


Window::Window()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, 1);
}

void Window::createWindow()
{
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }    

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  
    
    Renderer renderer;

    while(!glfwWindowShouldClose(window))
    {
        renderer.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

Window::~Window()
{
    glfwTerminate();
}