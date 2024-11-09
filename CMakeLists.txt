cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MusicVisualizer)

# Set the C++ standard and enforce it
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML package
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
find_package(X11 REQUIRED)  # Find the X11 package

# Define the source files
set(SOURCES
    src/main.cpp
    src/windowDrag.cpp
    src/bars.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories for the target
target_include_directories(${PROJECT_NAME} PRIVATE src include)

# Link SFML libraries and X11 libraries to the project
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system ${X11_LIBRARIES})

