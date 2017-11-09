cmake_minimum_required(VERSION 2.8)

project(LDPC)

# set(CMAKE_AUTOMOC ON)
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_PREFIX_PATH /usr/lib64/cmake)
# SET(CMAKE_FIND_LIBRARY_PREFIXES "")
# SET(CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-DQT_NO_DEBUG_OUTPUT)
add_definitions(-DQT_NO_WARNING_OUTPUT)

find_package(Qt5Core REQUIRED)

include_directories(LDPC-4Qt LDPC-codes "${Qt5Core_INCLUDE_DIRS}")

add_library(LDPC STATIC 
    libldpc.cpp
    LDPC-4Qt/ldpc4qt.cpp
    LDPC-4Qt/ldpccode.cpp
    LDPC-4Qt/ldpcdecode.cpp
    LDPC-4Qt/ldpcencode.cpp
    LDPC-4Qt/ldpcmakegen.cpp
    LDPC-4Qt/ldpcmakeldpc.cpp
    LDPC-4Qt/ldpcqconversions.cpp
    LDPC-4Qt/ldpctransmitsimulation.cpp
    LDPC-4Qt/ldpcverify.cpp
    # LDPC-4Qt/test.cpp
    LDPC-codes/alist-to-pchk.c
    LDPC-codes/alloc.c
    LDPC-codes/blockio.c
    LDPC-codes/channel.c
    LDPC-codes/check.c
    LDPC-codes/dec.c
    LDPC-codes/decode.c
    LDPC-codes/distrib.c
    LDPC-codes/enc.c
    LDPC-codes/encode.c
    LDPC-codes/extract.c
    LDPC-codes/intio.c
    LDPC-codes/make-gen.c
    LDPC-codes/make-ldpc.c
    LDPC-codes/make-pchk.c
    LDPC-codes/mod2convert-test.c
    LDPC-codes/mod2convert.c
    LDPC-codes/mod2dense-test.c
    LDPC-codes/mod2dense.c
    LDPC-codes/mod2sparse-test.c
    LDPC-codes/mod2sparse.c
    LDPC-codes/open.c
    LDPC-codes/pchk-to-alist.c
    LDPC-codes/print-gen.c
    LDPC-codes/print-pchk.c
    LDPC-codes/rand-src.c
    LDPC-codes/rand-test.c
    LDPC-codes/rand.c
    LDPC-codes/rcode.c
    LDPC-codes/transmit.c
    LDPC-codes/verify.c
    )

# link_libraries(Qt5::Core)

qt5_use_modules(LDPC Core)
