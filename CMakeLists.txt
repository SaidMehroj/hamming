cmake_minimum_required(VERSION 3.20)
project(Hamming-8-4)

set(CMAKE_CXX_STANDARD 14)
option(BUILD_SHARED_LIBS "Build is done using shared libs" ON)
include_directories(${PROJECT_SOURCE_DIR}/header)
add_library(hamming src/hamming.cpp)
add_executable(hamming_main main.cpp)
target_link_libraries(hamming_main PRIVATE hamming)