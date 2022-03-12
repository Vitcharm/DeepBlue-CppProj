cmake_minimum_required(VERSION 3.20)
project(proj2)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include/)
add_executable(LongNumAdding main.cpp include/num_calculator.h src/num_calculator.cpp)
