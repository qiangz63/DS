# cmake 最低版本需求
cmake_minimum_required(VERSION 3.22)

# 工程名称
project(DataStructure VERSION 1.0.0 LANGUAGES C CXX)

# 设置
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
#set (CMAKE_C_COMPILER "/usr/bin/x86_64-linux-gnu-gcc-11")
#set (CMAKE_CXX_COMPILER "/usr/bin/x86_64-linux-gnu-g++-11")
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS_DEBUG "-g -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_C_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_C_FLAGS_RELWITHDEGINFO "-O2 -g --DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEGINFO "-O2 -g --DNDEBUG")

# 头文件
configure_file(src/inc/cmake_template_version.h.in "${PROJECT_SOURCE_DIR}/src/inc/cmake_template_version.h")
include_directories(src/inc)

# 编译源码生成目标
add_executable(test src/test.cpp)
#add_executable(testTree src/testTree.cpp)
add_executable(testGraph src/testGraph.cpp)
#add_executable(search src/Search.cpp)
#add_executable(tree src/Tree.cpp)
add_executable(graph src/Graph.cpp)
#add_executable(sort src/Sort.cpp)
