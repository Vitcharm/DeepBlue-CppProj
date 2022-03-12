cmake_minimum_required(VERSION 3.20)
project(proj1)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include/)
add_executable(runQuiz main/do_quiz.cpp include/quiz_generator.h src/quiz_generator.cpp)
