#cmake_minimum_required(VERSION 3.28)
#project(Cipher)
#
#set(CMAKE_CXX_STANDARD 17)
#
#add_executable(Cipher
#        include/ciphers/CaesarCipher.h
#        include/ciphers/VigenereCipher.h
#        include/ciphers/XORCipher.h
#        include/utils/utils.h
#        src/ciphers/CaesarCipher.cpp
#        src/ciphers/VigenereCipher.cpp
#        src/ciphers/XORCipher.cpp
#        src/utils/utils.cpp
#        src/main.cpp)

cmake_minimum_required(VERSION 3.10)
project(Cipher)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for headers
include_directories(include)

# Collect all source files
file(GLOB_RECURSE SOURCES
        src/*.cpp
)

# Add the executable
add_executable(cipher ${SOURCES})
