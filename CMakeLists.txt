cmake_minimum_required(VERSION 3.0) 

project(CurveLib)  

set(SOURCE_DIR src/)
set(INCLUDE_DIR include/)

file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}*.cpp)

file(GLOB_RECURSE HEADER_FILES ${INCLUDE_DIR}*.h)

include_directories(${INCLUDE_DIR})

add_library(MyLibrary SHARED ${SOURCE_FILES} ${HEADER_FILES})

set_target_properties(MyLibrary PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(MyApp main.cxx)

target_link_libraries(MyApp PRIVATE MyLibrary)

set_target_properties(MyApp PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)