# just in case if we use the new feature of 3.22, so the user with 3.16 can not use this Cmake
cmake_minimum_required(VERSION 3.22)

# Whenever we would write C++, we use CXX, because the plus can be considered to the operator\
# and would'nt be counted, as a character to the language name. 
project(
    CppProjectTemplate
    VERSION 1.0.0 
    LANGUAGES C CXX
)

add_executable(main main.cpp)

