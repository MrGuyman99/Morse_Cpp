#include "morse.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>

void morse::cpp_to_morse(std::string FilePath) {
	std::fstream og_file(FilePath);
	char current_character;
	std::string converted_file;
	std::unordered_map<char, std::string> morse_translate = {
		{'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
		{'E', "."},	   {'F', "..-."}, {'G', "--."},	 {'H', "...."},
		{'I', ".."},   {'J', ".---"}, {'K', "-.-"},	 {'L', ".-.."},
		{'M', "--"},   {'N', "-."},	  {'O', "---"},	 {'P', ".--."},
		{'Q', "--.-"}, {'R', ".-."},  {'S', "..."},	 {'T', "-"},
		{'U', "..-"},  {'V', "...-"}, {'W', ".--"},	 {'X', "-..-"},
		{'Y', "-.--"}, {'Z', "--.."}, {' ', "/"}};

	if (!og_file.is_open()) {
		std::cerr << "Could not open file at path " << FilePath << std::endl;
		return;
	}
	// Reading the file character by character and translating it
	while (og_file.get(current_character)) {
		converted_file += morse_translate[current_character];
		converted_file += " ";
	}
	std::cout << converted_file << std::endl;
	og_file.close();
}
void morse::morse_to_cpp(std::string FilePath) {}