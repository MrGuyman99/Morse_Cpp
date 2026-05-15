# Morse Code C++

**What happens if you turn morse code into a programming language?**

This is that! You can now write your favorite C++ using morse characters instead of regular ASCII characters and make whatever you want. Porbably the strangest way to make an esolang, but it was definetly easier than building my own syntax/compiler

## Example:

```cpp
#include <iostream>

int main() {
	std::cout << "Hello World\n";
	return 0;
}
```
#### Converts to:

```
# .. -. -.-. .-.. ..- -.. . / < .. --- ... - .-. . .- -- > 
 
 .. -. - / -- .- .. -. ( ) / { 
 	 ... - -.. ---... ---... -.-. --- ..- - / < < / " H . .-.. .-.. --- / W --- .-. .-.. -.. \ -. " -.-.-. 
 	 .-. . - ..- .-. -. / ----- -.-.-. 
 } 
```
#### And vice versa

## Conversion Table (ASCII to Morse):
```cpp
{'a', ".-"},	 {'b', "-..."},	  {'c', "-.-."},   {'d', "-.."},
{'e', "."},		 {'f', "..-."},	  {'g', "--."},	   {'h', "...."},
{'i', ".."},	 {'j', ".---"},	  {'k', "-.-"},	   {'l', ".-.."},
{'m', "--"},	 {'n', "-."},	  {'o', "---"},	   {'p', ".--."},
{'q', "--.-"},	 {'r', ".-."},	  {'s', "..."},	   {'t', "-"},
{'u', "..-"},	 {'v', "...-"},	  {'w', ".--"},	   {'x', "-..-"},
{'y', "-.--"},	 {'z', "--.."},	  {' ', "/"},	   {'1', ".----"},
{'2', "..---"},	 {'3', "...--"},  {'4', "....-"},  {'5', "....."},
{'6', "-...."},	 {'7', "--..."},  {'8', "---.."},  {'9', "----."},
{'0', "-----"},	 {'?', "..--.."}, {'!', "-.-.--"}, {'.', ".-.-.-"},
{',', "--..--"}, {';', "-.-.-."}, {':', "---..."}, {'+', ".-.-."},
{'-', "-....-"}, {'/', "-..-."},  {'=', "-..-"}
```
**All morse characters should be seperated by spaces when programming!!**

## How to Use:
	1.) Setup your compiler/build system as you normally would
	2.) Clone and compile this repository and put the compiled executable in the project's directory
	3.) Make it so before the project is compiled, the source files are being translated by the compiled executable in cpp mode
	4.) After compilation make it so the project is re-translated back into morse by using tyhe compile executable in morse mode
```cmake
# Example CMake configuration using Morse-Cpp
cmake_minimum_required(VERSION 3.24)
project(Test)
set(CMAKE_BUILD_TYPE Debug)
# The CMAKE_RUNTIME_OUTPUT_DIRECTORY is set to the root folder here (Where Morse_Code is located)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
	set(CMAKE_CXX_STANDARD 11)
endif()

# Currently Only Supports One File
set(SOURCE_FILES
	src/main.cpp
)

# Translating morse --> C++ before compilation
add_custom_target(Translate
	COMMAND ./Morse_Code cpp ${SOURCE_FILES}
	WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
	COMMENT "Translating morse --> c++"
)

# Compiling
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Translating C++ --> morse after compilation
add_custom_command( 
	TARGET ${PROJECT_NAME}
	POST_BUILD
	COMMAND ./Morse_Code morse ${SOURCE_FILES}
	WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
	COMMENT "Translating c++ --> morse"
	VERBATIM
)

add_dependencies(${PROJECT_NAME} Translate)
```

## Semantics:
- At the moment we assume that every letter is lowercased (since all C++ keywords are lowercased), but I could make something like a control character to be able to denote uppercase and lowercase text for strings and variable names.

- Every Character in the morse also needs to have a space before and after it, even those not written in morse. I could maybe fix this, but it's a bug not a feature ;)

- All ASCII characters not supported by translation get ignored (Example: Capital H and W in "Hello World would still be present in the morse translated version)

- Also does only support one file at a time at the moment lol

**As Per Usual, made with love (and a newfound love of ~~macros~~ unordered lists) - MrGuyman99**