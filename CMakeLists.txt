cmake_minimum_required(VERSION 3.24)
project(Morse_Code)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
	set(CMAKE_CXX_STANDARD 11)
endif()

set(SOURCE_FILES
	src/main.cpp
	src/morse.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
