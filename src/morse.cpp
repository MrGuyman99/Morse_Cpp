#include "morse.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>

// Translates characters into morse, puts spaces between each morse character
// Ignores things if they aren't supported
void morse::cpp_to_morse(std::string FilePath) {
	std::ifstream og_file(FilePath);
	char current_character;
	std::string converted_file;
	std::unordered_map<char, std::string> morse_translate = {
		{'a', ".-"},	 {'b', "-..."},	  {'c', "-.-."},   {'d', "-.."},
		{'e', "."},		 {'f', "..-."},	  {'g', "--."},	   {'h', "...."},
		{'i', ".."},	 {'j', ".---"},	  {'k', "-.-"},	   {'l', ".-.."},
		{'m', "--"},	 {'n', "-."},	  {'o', "---"},	   {'p', ".--."},
		{'q', "--.-"},	 {'r', ".-."},	  {'s', "..."},	   {'t', "-"},
		{'u', "..-"},	 {'v', "...-"},	  {'w', ".--"},	   {'x', "-..-"},
		{'y', "-.--"},	 {'z', "--.."},	  {' ', "/"},	   {'1', ".----"},
		{'2', "..---"},	 {'3', "...--"},  {'4', "....-"},  {'5', "....."},
		{'6', "-...."},	 {'7', "--..."},  {'8', "--.."},   {'9', "----."},
		{'0', "-----"},	 {'?', "..--.."}, {'!', "-.-.--"}, {'.', ".-.-.-"},
		{',', "--..--"}, {';', "-.-.-."}, {':', "---..."}, {'+', ".-.-."},
		{'-', "-....-"}, {'/', "-..-."},  {'=', "-..-"}};

	if (!og_file.is_open()) {
		std::cerr << "Could not open file at path " << FilePath << std::endl;
		return;
	}
	// Reading the file character by character and translating it
	while (og_file.get(current_character)) {
		try {
			converted_file += morse_translate.at(current_character);
			converted_file += " ";
		} catch (const std::out_of_range& e) {
			std::cerr << "Character Not Supported! Character is: '"
					  << current_character << "' Ignoring\n";
			if (!converted_file.empty() && converted_file.back() == ' ') {
				converted_file.pop_back();
			}
			converted_file += current_character;
		}
	}
	og_file.close();
	std::ofstream write_file(FilePath, std::ios::app);
	write_file << std::endl << "--------------\n" << converted_file;
}
void morse::morse_to_cpp(std::string FilePath) {}