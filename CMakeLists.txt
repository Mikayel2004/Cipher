cmake_minimum_required(VERSION 3.10)
project(Cipher)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include/ to the search path
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find all .cpp source files in src/
file(GLOB_RECURSE SOURCES src/*.cpp)

# Build executable from all .cpp files
add_executable(cipher ${SOURCES}
        include/ciphers/VigenereCipher.h
        include/ciphers/XORCipher.h
        include/utils/utils.h)
