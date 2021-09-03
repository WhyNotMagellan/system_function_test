cmake_minimum_required(VERSION 2.8)

#set project name
project(test_for_linux)
set(root_path ${CMAKE_CURRENT_SOURCE_DIR})

# 添加编译选项
add_definitions(-std=c++11)

# 添加头文件

# 添加执行文件
file(GLOB time_files ${root_path}/src/time/*cpp)

# 编译执行文件
add_executable(test_for_time ${time_files})