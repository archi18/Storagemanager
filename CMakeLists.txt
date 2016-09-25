cmake_minimum_required(VERSION 3.6)
project(assign1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    dberror.c
    dberror.h
    storage_mgr.c
    storage_mgr.h
    test_assign1_1.c
    test_helper.h)

add_executable(assign1 ${SOURCE_FILES})