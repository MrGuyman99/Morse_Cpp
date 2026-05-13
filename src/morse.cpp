#include "morse.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>

// Macro So We don't have to write an insane amount of if statements
#define CheckCharacter(check_character, compare_character) \
	({                                                     \
		do {                                               \
			if (check_character == compare_character) {    \
				std::cout << ".-\n";                       \
			}                                              \
		} while (0);                                       \
	})

void morse::cpp_to_morse(std::string FilePath) {
	std::fstream convert_file(FilePath);
	std::string current_character;
	if (!convert_file.is_open()) {
		std::cerr << "Could not open file at path " << FilePath << std::endl;
		return;
	}
	// getline reads character by character
	while (getline(convert_file, current_character)) {
		CheckCharacter(current_character, "A");
	}
	convert_file.close();
}
void morse::morse_to_cpp(std::string FilePath) {}