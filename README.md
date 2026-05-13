# Morse Code C++

**What happens if you turn morse code into a programming language?**

The goal of this project is to find the answer to that exact question. I want to make a prgram that can convert morse to C++ to then be compiled, essentially turning morse code into it's own fully fledged esolang. The way I'm planning to accomplish this is by translating every morse code character into ASCII, which will then get compiled by any regular C++ compiler.

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
#..-.-.-..-....- -...<..-- -... -.-...- -->

..-.- / --.-..-.-.--.-.--.- {
	... - -..-- -... -- -... -.-.-- -..- -<< ".-..-. .... . .-.. .-.. --- / .-- --- .-. .-.. -.. .-..-. \-." -.-.-.
}
```
#### And vice versa

## Semantics:
At the moment we assume that every letter is lowercased (since all C++ keywords are lowercased), but I could make something like a control character to be able to denote uppercase and lowercase text for strings and variable names.

**As Per Usual, made with love (and a newfound love of macros) - MrGuyman99**