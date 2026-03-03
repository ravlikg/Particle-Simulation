cmake_minimum_required(VERSION 3.22)
project(particleSimulation)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
)

FetchContent_MakeAvailable(SFML)

add_executable(particleSimulation source/main.cpp)

target_include_directories(particleSimulation PRIVATE include)

target_link_libraries(particleSimulation
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)