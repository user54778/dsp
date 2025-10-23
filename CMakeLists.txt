cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 17) # Compile as C++17

project(DSPLearning
        VERSION 0.1.0
        DESCRIPTION "A Digital Signal Processing Library"
        LANGUAGES C CXX
)

add_executable(noise_gen src/ch02-noise/noise_gen.cpp)

