cmake_minimum_required(VERSION 3.10)
set_property(GLOBAL PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

project(Limpeza
  LANGUAGES CXX
  VERSION 0.0.1
)

add_compile_options(-g -Wall -Wextra -Wpedantic -pedantic)
if(CHECK_MEM)
  message("Compilando com libasan. Saiba mais: <https://github.com/google/sanitizers/>")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
endif()

set (CMAKE_CXX_STANDARD 23)
add_executable(limpeza main.cpp clean.cpp)
