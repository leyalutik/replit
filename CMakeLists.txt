cmake_minimum_required(VERSION 3.1)

project(dyn)
add_executable(dyn main.cpp)

include_directories (source)

add_subdirectory(source)

target_link_libraries(dyn library_source)