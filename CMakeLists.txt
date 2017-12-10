cmake_minimum_required(VERSION 3.8)
project(220FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Bookstore.cpp Book.cpp Person.cpp)
add_executable(220FinalProject ${SOURCE_FILES})