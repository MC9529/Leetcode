#cmake最低版本需求，不加入此行会受到警告信息
cmake_minimum_required(VERSION 2.6)
project(hello) #项目名称

#add_compile_options(-std=c++11)


##  build
# SET(CMAKE_CXX_FLAGS "-std=c++11 -O2 -g -Wall ${CMAKE_CXX_FLAGS} -lm")
SET(CMAKE_CXX_FLAGS "-std=c++11 -O2 -g -Wall ${CMAKE_CXX_FLAGS} -lm")

include_directories(source)
aux_source_directory(source SRC_LIST)

find_package(Eigen3)
INCLUDE_DIRECTORIES(SYSTEM ${EIGEN3_INCLUDE_DIR})

add_executable(hello main.cpp ${SRC_LIST})


