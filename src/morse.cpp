#include "morse.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>

void morse::cpp_to_morse(std::string FilePath) {
	std::ifstream og_file(FilePath);
	char current_character;
	std::string converted_file;
	// Map of all the characters and their morse code counterparts
	std::unordered_map<char, std::string> morse_translate = {
		{'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
		{'E', "."},	   {'F', "..-."}, {'G', "--."},	 {'H', "...."},
		{'I', ".."},   {'J', ".---"}, {'K', "-.-"},	 {'L', ".-.."},
		{'M', "--"},   {'N', "-."},	  {'O', "---"},	 {'P', ".--."},
		{'Q', "--.-"}, {'R', ".-."},  {'S', "..."},	 {'T', "-"},
		{'U', "..-"},  {'V', "...-"}, {'W', ".--"},	 {'X', "-..-"},
		{'Y', "-.--"}, {'Z', "--.."}, {' ', "/"}};

	// If the file isn't open at all exit the program
	if (!og_file.is_open()) {
		std::cerr << "Could not open file at path " << FilePath << std::endl;
		return;
	}
	// Reading the file character by character and translating it
	while (og_file.get(current_character)) {
		try {
			// If a supported character is selected translate it and add it to
			// the final string
			converted_file += morse_translate.at(current_character);
			converted_file += " ";
		} catch (const std::out_of_range& e) {
			// If an unsupported character is selected first ignore it
			std::cerr << "=Character Not Supported! Character is: '"
					  << current_character << "' Ignoring\n";
			// If the last character was a space delete it
			// This is so things like () and "" work properly Take ( " Hello " )
			// compared to ("Hello")
			if (converted_file.back() == ' ') {
				converted_file.pop_back();
			}
			converted_file += current_character;
		}
	}
	// Close the read only file, open a write file, then append the entire
	// converted string to it
	// TODO: Completely convert the file, appending is just for testing
	og_file.close();
	std::ofstream write_file(FilePath, std::ios::app);
	write_file << std::endl << converted_file;
}
void morse::morse_to_cpp(std::string FilePath) {}