cmake_minimum_required(VERSION 3.5)
project(human_gl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(libs/nanogui)
include_directories(libs/nanogui/include)
include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

set(
	SOURCE_FILES
	src/main.cpp
	src/Matrix.cpp
	src/Vector.cpp
	src/Mesh/Mesh.cpp
	src/Mesh/TorsoMesh.cpp
)
add_executable(human_gl ${SOURCE_FILES})
target_link_libraries(human_gl nanogui ${NANOGUI_EXTRA_LIBS})