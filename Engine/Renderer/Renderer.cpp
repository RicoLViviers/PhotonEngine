#include "Renderer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>

#include "../Scene/Entity.h"

#include "Texture/Texture.h"

#include "glad/glad.h"

using namespace std;


string loadShaderSource(const string& filePath)
{
    ifstream shaderFile;
    stringstream shaderStream;

    shaderFile.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        shaderFile.open(filePath);
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
    } catch (const ifstream::failure& e) {
        cerr << "ERROR::SHADER::FILE_NOT_SUCESFFULLY_READ: " << filePath << endl;
        return "";
    }

    return shaderStream.str();
}

Renderer::Renderer()
{
    //Load vertex shader
    string vShaderSource = loadShaderSource("./Shaders/shader.vert");
    const char *vertexShaderSource = vShaderSource.c_str();

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);


    // Fragment shader
    string fShaderSource = loadShaderSource("./Shaders/shader.frag");
    const char *fragmentShaderSource = fShaderSource.c_str();

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    // Error handling
    int  success;
    char infoLog[512];


    // Vertex shader error
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Fragment shader error
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Shader program error
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::SHADER_PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glUseProgram(shaderProgram);

    // Delete shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  

    Texture texture("./assets/brick.jpg");

    texture.bind();

    std::vector<float> vertices1 = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };

    std::vector<unsigned int> indices1 = {
        0, 1, 3,
        1, 2, 3
    };

    auto mesh = std::make_shared<Mesh>(vertices1, indices1);

    cube = std::make_unique<Entity>(mesh);
}

Renderer::~Renderer()
{
        
    
}

void Renderer::render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    

    cube->getMesh().draw();

}