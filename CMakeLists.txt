cmake_minimum_required(VERSION 3.16)

project(nsh
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(nsh
    src/main.cpp
    src/parser.cpp
    src/executor.cpp
)

add_executable(parser_test
    tests/parser_test.cpp
    src/parser.cpp
)

add_executable(executor_test
    tests/executor_test.cpp
    src/executor.cpp

)

target_include_directories(executor_test PRIVATE
    include 

)

target_include_directories(parser_test PRIVATE
    include
)

target_include_directories(nsh PRIVATE
    include

)