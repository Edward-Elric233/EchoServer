cmake_minimum_required(VERSION 3.21)
project(Server)

set(CMAKE_CXX_STANDARD 14)

set(muduo_build_path /home/edward/C++/Muduo/build/release-cpp11)
set(muduo_include_path /home/edward/C++/Muduo/muduo/)

include_directories(${muduo_include_path})

add_executable(Server main.cpp Server.cpp Server.h utils.h)

target_link_libraries(Server ${muduo_build_path}/lib/libmuduo_net.a ${muduo_build_path}/lib/libmuduo_base.a pthread)