#include <iostream>
#include "morse.hpp"

// argc --> Argument Count
// argv --> Points to an argument
int main(int argc, char* argv[]) {
	if (argv[1] == nullptr) {
		std::cerr << "Please enter a file path\n";
	} else {
		morse::cpp_to_morse(argv[1]);
	}
	return 0;
}