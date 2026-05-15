#include <iostream>
#include "morse.hpp"

// argc --> Argument Count
// argv --> Points to an argument
int main(int argc, char* argv[]) {
	std::string check;
	if (argc > 1) {
		check = argv[1];
	} else {
		std::cerr << "Please enter 'morse' for cpp --> morse, 'cpp' for morse "
					 "--> cpp\n";
	}

	if (argv[2] == nullptr) {
		std::cerr << "Please enter a file path\n";
	} else if (check == "morse") {
		morse::cpp_to_morse(argv[2]);
	} else if (check == "cpp") {
		morse::morse_to_cpp(argv[2]);
	} else {
		std::cerr << "Please enter a type!\n";
	}

	return 0;
}