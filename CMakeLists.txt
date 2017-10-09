cmake_minimum_required(VERSION 2.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH /usr/lib64/cmake)
SET(CMAKE_FIND_LIBRARY_PREFIXES "")
SET(CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})

find_package(Qt5Core REQUIRED)

project(testLDPC)

set(SOURCES 
    libLDPC/libldpc.cpp
    LDPC-4Qt/ldpc4qt.cpp
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(libLDPC LDPC-4Qt)

add_subdirectory(libLDPC)

# add_executable(testLDPC testLDPC.cpp ${SOURCES})

link_libraries(Qt5::Core libLDPC)
# link_libraries(libLDPC)
