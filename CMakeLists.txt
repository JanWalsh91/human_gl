cmake_minimum_required(VERSION 3.5)
project(human_gl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(libs/nanogui)
include_directories(libs/nanogui/include)
include_directories(libs/nanogui/ext/glad/include)


include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

set(
	SOURCE_FILES
	src/main.cpp
	src/Shader.cpp
	src/OpenGLWindow.cpp
	src/Cycle.cpp
	src/Matrix.cpp
	src/Vector.cpp
	src/Mesh/Mesh.cpp
	src/Mesh/TorsoMesh.cpp
	src/Mesh/ArmMesh.cpp
	src/Mesh/LegMesh.cpp
	src/Mesh/HeadMesh.cpp
	src/Mesh/LowerArmMesh.cpp
	src/Mesh/LowerLegMesh.cpp
	src/Mesh/LowerLegMesh.cpp
	src/Mesh/HandMesh.cpp
	src/Mesh/FootMesh.cpp
	src/HumanGL.cpp
	src/GUI.cpp
	src/KeyFrame.cpp
	libs/nanogui/ext/glad/src/glad.c
)
add_executable(human_gl ${SOURCE_FILES})
target_link_libraries(human_gl nanogui ${NANOGUI_EXTRA_LIBS})
