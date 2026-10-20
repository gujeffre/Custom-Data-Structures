cmake_minimum_required(VERSION 3.15)
project(LeakProofContainers VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(custom_structures main.cpp)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(custom_structures PRIVATE -fsanitize=address -g -O1)
    target_link_options(custom_structures PRIVATE -fsanitize=address)
elseif(MSVC)
    target_compile_options(custom_structures PRIVATE /fsanitize=address /Zi)
endif()
