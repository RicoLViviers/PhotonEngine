cmake_minimum_required(VERSION 3.15)

project(PhotonEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
    GIT_SHALLOW TRUE
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)


find_package(OpenGL REQUIRED)

set(SOURCES
    Sandbox/Sandbox.cpp
    Engine/Core/PhotonEngine.cpp
    Engine/Renderer/Renderer.cpp
    Engine/Window/Window.cpp
    Engine/Window/Window.cpp
    Engine/Renderer/Texture/Texture.cpp
    Engine/Renderer/Camera/Camera.cpp

    Engine/Scene/Transform/Transform.cpp
    Engine/Scene/MeshComponent/MeshComponent.cpp
    Engine/Scene/MeshComponent/Mesh.cpp
    Engine/Scene/Entity.cpp


    external/glad/src/glad.c


    external/stb/stb_vorbis.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Copy the shaders folder right next to the executable after building
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/Shaders/"
            "$<TARGET_FILE_DIR:PhotonEngine>/Shaders/"
    COMMENT "Syncing shaders to the build directory..."
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/assets/"
            "$<TARGET_FILE_DIR:PhotonEngine>/assets/"
    COMMENT "Syncing assets to the build directory..."
)

target_include_directories(${PROJECT_NAME} PRIVATE
    Engine
    external/glad/include
    external/stb
    external/glm
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    OpenGL::GL
)
