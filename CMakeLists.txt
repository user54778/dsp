cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 17) # Compile as C++17

project(DSPLearning
        VERSION 0.1.0
        DESCRIPTION "A Digital Signal Processing Library"
        LANGUAGES C CXX
)

# create lcg/gaussian library
add_library(lcg
  src/ch02-noise/lcg.cpp
  src/ch02-noise/lcg.h
  src/ch02-noise/gaussian.cpp
  src/ch02-noise/gaussian.h
)

# where headers are
target_include_directories(lcg PUBLIC src/ch02-noise)

# create executable
add_executable(noise_gen src/ch02-noise/main.cpp)

# link library to executable
target_link_libraries(noise_gen PRIVATE lcg)

# all above instead of one big add_library() command
