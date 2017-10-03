cmake_minimum_required(VERSION 2.8)

# find_package(Qt5Core REQUIRED)

project(testLDPC)

# set(SOURCES 
#     libLDPC/libldpc.cpp
#     LDPC-4Qt/ldpc4qt.cpp
#     )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(libLDPC LDPC-4Qt)

add_subdirectory(libLDPC)

add_executable(testLDPC testLDPC.cpp ${SOURCES})

target_link_libraries(testLDPC libLDPC)
