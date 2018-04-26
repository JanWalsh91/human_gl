cmake_minimum_required(VERSION 3.5)
project(nanogui_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(libs/nanogui)
include_directories(libs/nanogui/include)
include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

set(SOURCE_FILES example3.cpp)
add_executable(nanogui_test ${SOURCE_FILES})
target_link_libraries(nanogui_test nanogui ${NANOGUI_EXTRA_LIBS})
