cmake_minimum_required(VERSION 3.22)
project(particleSimulation)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Принудительно собираем SFML статически
set(SFML_STATIC_LIBRARIES TRUE CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
)

FetchContent_MakeAvailable(SFML)

include_directories(include)
add_executable(particleSimulation source/main.cpp)

add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/assets
)
add_dependencies(particleSimulation copy_assets)

# Если ты на Windows и хочешь убрать консольное окно в релизе:
if(WIN32 AND NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_options(particleSimulation PRIVATE "-mwindows")
endif()

target_link_libraries(particleSimulation
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

# Чтобы не таскать за собой стандартные библиотеки MinGW
if(NOT MSVC)
    target_link_options(particleSimulation PRIVATE -static -static-libgcc -static-libstdc++)
endif()
