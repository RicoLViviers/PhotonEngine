#include <iostream>

#include "Window/Window.h"
#include "PhotonEngine.h"

using namespace std;

PhotonEngine::PhotonEngine()
{
}

PhotonEngine::~PhotonEngine()
{

}

void PhotonEngine::helloWorld()
{
    Window window;

    window.createWindow();

    window.~Window();
}