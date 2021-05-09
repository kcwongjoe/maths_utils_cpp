cmake_minimum_required(VERSION 3.5)

#******Project******
project(maths_utils LANGUAGES CXX)

#******Setting******
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#  C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++lastest")


#******Built Header and Source Files list******

# Header Folder
set(MY_HEADER_FOLDER)
LIST(APPEND MY_HEADER_FOLDER "./src")

# Source Folder
set(MY_SOURCE_FOLDER)
LIST(APPEND MY_SOURCE_FOLDER "./src")

# ******Include files******
include_directories(
    ./include/maths_utils
    ./src
)

#******Add source files******
add_subdirectory("./src")
