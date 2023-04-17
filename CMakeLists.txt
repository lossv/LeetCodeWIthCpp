cmake_minimum_required(VERSION 2.8)
project(LeetCodeWIthCpp)
set(CMAKE_CXX_STANDARD 20)

include_directories(comm)

add_subdirectory(offer)

aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST)

foreach(var ${SRC_LIST})
    string(REGEX REPLACE ".*/" "" var ${var})
    string(REGEX REPLACE ".cpp" "" tgt ${var})
    add_executable(${tgt} ${var})
endforeach(var)

add_subdirectory(Thread)
